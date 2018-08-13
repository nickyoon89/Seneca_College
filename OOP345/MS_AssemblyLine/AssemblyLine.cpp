#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Item.h"
#include "Utilities.h"

void RunM1(std::ofstream&);
std::vector<Item> Inventory;

//UNCOMMENT FOR MILESTONE 2
#include "CustomerOrder.h"
void RunM2(std::ofstream&);
std::vector<CustomerOrder>Orders;


//UNCOMMENT FOR MILESTONE 3
#include "Task.h"
#include "LineManager.h"
void RunM3(std::ofstream&);
std::vector<Task*> Tasks;

int main(int argc, char *argv[])
{
	Utilities::setDelimiter('|');

	std::ofstream ofs("Output.txt");
	if (!ofs)
	{
		std::cerr << "ERROR:  Failed to open output.txt file";
		exit(0);
	}

	//**************//
	//RunM1(ofs);
	//RunM2(ofs);
	RunM3(ofs);
	//**************//

	ofs.close();

	return 1;
}


void RunM1(std::ofstream& os)
{
	std::ifstream file("inventory.txt");
	if (!file)
	{
		os << "*** Unable to open inventory.txt file" << std::endl;
	}

	std::string record;
	while (!file.eof())
	{
		std::getline(file, record);
		Item newItem(record);
		Inventory.push_back(std::move(newItem));
	}

	for (size_t i = 0; i < Inventory.size(); i++)
		Inventory[i].display(os,true);

	file.close();

	//Select an object and verify all the functionality it working
	os << "\nManual Validation" << std::endl;
	os << "getName(): " << Inventory[0].getName() << std::endl;
	os << "getSerialNumber(): " << Inventory[0].getSerialNumber() << std::endl;
	os << "getSerialNumber(): " << Inventory[0].getSerialNumber() << std::endl;
	os << "getQuality(): " << Inventory[0].getQuantity() << std::endl;
	Inventory[0].updateQuantity();
	os << "getQuality(): " << Inventory[0].getQuantity() << std::endl;
	os << "\n************************\n";

	std::cin.get();
}


void RunM2(std::ofstream& os)
{
	RunM1(os);
	std::ifstream file("CustomerOrders.txt");
	if (!file)
		os << "**** Unable to open CustomerOrders.txt file" << std::endl;

	std::string record;
	while (!file.eof())
	{
		std::getline(file, record);
		CustomerOrder newOrder(record);
		Orders.push_back(std::move(newOrder));
	}

	for (size_t i = 0; i < Orders.size(); i++)
		Orders[i].Display(os);

	file.close();

	os << "\nManual Validation" << std::endl;
	Orders[Orders.size() - 1].Display(os);
	CustomerOrder tmp(std::move(Orders[Orders.size()-1]));
	Orders.pop_back();
	tmp.Display(os);
	os << "*******" << std::endl;
	std::string strRecord = "Chloe|Flight PC|CPU|GPU|Power Supply";
	CustomerOrder tmp2(strRecord);
	tmp2.Display(os);
	tmp2 = std::move(Orders[Orders.size()-1]);
	Orders.pop_back();
	tmp2.Display(os);
	os << "*******" << std::endl;
	if (tmp2.getOrderFillState())
		os << "getFillStatus(): FILLED" << std::endl;
	else
		os << "getFillStatus(): MISSING" << std::endl;

	tmp2.fillItem(Inventory[0], os);

	if (tmp2.getOrderFillState())
		os << "getFillStatus(): FILLED" << std::endl;
	else
		os << "getFillStatus(): MISSING" << std::endl;

	for(size_t i=0; i < Inventory.size(); i++)
		tmp2.fillItem(Inventory[i], os);

	if (tmp2.getOrderFillState())
		os << "getFillStatus(): FILLED" << std::endl;
	else
		os << "getFillStatus(): MISSING" << std::endl;
}



void RunM3(std::ofstream& os)
{
	std::ifstream file("inventory.txt");
	if (!file)
	{
		os << "*** Unable to open inventory.txt file" << std::endl;
	}

	std::string record;
	while (!file.eof())
	{
		std::getline(file, record);
		Tasks.push_back(new Task(record));
	}

	file.close();

	for (size_t i = 0; i < Tasks.size(); i++)
		Tasks[i]->display(os, true);

	file.close();

	//Select an object and verify all the functionality it working
	os << "\nManual Validation" << std::endl;
	os << "getName(): " << Tasks[0]->getName() << std::endl;
	os << "getSerialNumber(): " << Tasks[0]->getSerialNumber() << std::endl;
	os << "getSerialNumber(): " << Tasks[0]->getSerialNumber() << std::endl;
	os << "getQuality(): " << Tasks[0]->getQuantity() << std::endl;
	Tasks[0]->updateQuantity();
	os << "getQuality(): " << Tasks[0]->getQuantity() << std::endl;
	os << "\n************************\n";

	//Load the customer orders
	std::ifstream file2("CustomerOrders.txt");
	if (!file2)
		os << "**** Unable to open CustomerOrders.txt file" << std::endl;

	while (!file2.eof())
	{
		std::getline(file2, record);
		CustomerOrder newOrder(record);
		Orders.push_back(std::move(newOrder));
	}

	for (size_t i = 0; i < Orders.size(); i++)
		Orders[i].Display(os);

	file2.close();

	std::string filename = "AssemblyLine.txt";
	LineManager lm(filename, Tasks, Orders);

	while (!lm.Run(os)) {};		//loop running the assembly line until complete
}
