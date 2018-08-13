#include "LineManager.h"
#include "Utilities.h"

//Constructor sets the assembly line up by setting up the tasks pNextTask information
//and moves all the CustomerOrder objects into the ToBeFilled queue
LineManager::LineManager(std::string& fileName, std::vector<Task*>& tasks, std::vector<CustomerOrder>& orders) {
	bool more;
	size_t pos;
	size_t count;
	size_t formerNo;
	Utilities util;
	std::ifstream file(fileName);
	std::string record;
	if (!file)
	{
		std::cout << "*** Unable to open "+ fileName +" file" << std::endl;
	}
	while (!file.eof())
	{
		more = true; pos = 0u; count = 0u;
		std::getline(file, record);
		std::string former = util.extractToken(record, pos, more);
		std::string next = "";
		if(more) next = util.extractToken(record, pos, more);
		for (size_t i = 0; i < tasks.size(); i++) {
			if (tasks[i]->getName() == former) {
				formerNo = i;
				break;
			}
		}
		if(next.size()!=0){
			for (size_t i = 0; i < tasks.size(); i++) {
				if (tasks[i]->getName() == next) {
					tasks[formerNo]->setNextTask(*tasks[i]);
					break;
				}
			}
		}
		else
			tasks[formerNo]->setNextTask(*AssemblyLine[0]);
		AssemblyLine.push_back(tasks[formerNo]);
	}
	for (size_t i = 0; i < orders.size(); i++) {
		ToBeFilled.push_back(std::move(orders[i]));
	}	
}

//Processes each assembly line task and moves the CustomerOrders through the line
//Returning true if all items have been completed
bool LineManager::Run(std::ostream& os) {
	size_t orderNum = ToBeFilled.size();
	for (size_t j = 0; j < orderNum; j++) {
		*AssemblyLine[0] += std::move(ToBeFilled[j]);
		Completed.emplace_back();
	}
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->RunProcess(os);
		if (i == AssemblyLine.size() - 1) {
			for(size_t j=0; j<orderNum; j++)
			AssemblyLine[0]->getCompleted(Completed[j]);
		}
	}
	if (Completed.size() == orderNum) {
		os << std::endl << "COMPLETED" << std::endl;
		for (size_t i = 0; i < Completed.size(); i++)
			Completed[i].Display(os);
		return true;
	};
	return false;
}