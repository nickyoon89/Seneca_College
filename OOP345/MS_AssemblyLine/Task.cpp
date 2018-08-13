#include "Task.h"

//Constructor
Task::Task(std::string& file) : Item::Item(file) {
	pNextTask = nullptr;
}
//This function fills the last order on the order queue
void Task::RunProcess(std::ostream& os) {
	size_t max = Orders.size();
	size_t count = 0;
	while (!Orders.empty()&&count!=max) {
		while (!(Orders.back().getItemFillState(this->getName()))) {
			Orders.back().fillItem(*this, os);
		}
		if (this->pNextTask != nullptr) {
			*this->pNextTask += std::move(Orders.back());
			Orders.pop_back();
		}
		count++;
	}
}
//This function moves the completed task to the next part of the assembly line
bool Task::MoveTask() {
	if (Orders.empty() == false) {
		if (Orders.back().getOrderFillState() == true) {
			pNextTask->Orders.push_back(std::move(Orders.back()));
			Orders.pop_back();
		}
	}
	else {
		return false;
	}
	return true;
}								
//Sets up the pointer to the next task if the tasks names line up
void Task::setNextTask(Task& task) {
	pNextTask = &task;
}						
bool Task::getCompleted(CustomerOrder &co) {
	if (Orders.empty()) return false;
	co = std::move(Orders.back());
	Orders.pop_back();
	return true;
}
void Task::Validate(std::ostream& os) {
	os << "Validate" << std::endl;
	os << this->getName() << std::endl;
	os << "Next:" << pNextTask->getName() << std::endl;
}
//Move a CustomerOrder into the orders queue
Task& Task::operator+=(CustomerOrder&& newOrder) {
	Orders.push_front(std::move(newOrder));
	return *this;
}				