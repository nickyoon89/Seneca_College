#pragma once
#include <iostream>
#include <deque>
#include <fstream>
#include <vector>
#include "CustomerOrder.h"
#include "Task.h"

class LineManager
{
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;		//Queue of Customer Orders to be filled
	std::deque<CustomerOrder> Completed;		//Queue of Customer Orders completed
	unsigned int CustomerOrder_Count;			//The number of customer orders the process started with

public:
	//Constructor sets the assembly line up by setting up the tasks pNextTask information
	//and moves all the CustomerOrder objects into the ToBeFilled queue
	LineManager(std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);

	//Processes each assembly line task and moves the CustomerOrders through the line
	//Returning true if all items have been completed
	bool Run(std::ostream&);
};