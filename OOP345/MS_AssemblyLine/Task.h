#pragma once
#include <iostream>
#include <deque>
#include "Item.h"
#include "CustomerOrder.h"


class Task : public Item
{
	std::deque<CustomerOrder> Orders;				//Current orders at this station
	
	Task* pNextTask;								//Reference to the next task

public:
	Task(std::string&);								//Constructor

	Task(Task&) = delete;
	Task& operator=(Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&&) = delete;

	void RunProcess(std::ostream&);					//This function fills the last order on the order queue
	bool MoveTask();								//This function moves the completed task to the next part of the assembly line
	void setNextTask(Task&);						//Sets up the pointer to the next task if the tasks names line up
	bool getCompleted(CustomerOrder &);
	void Validate(std::ostream&);

	Task& operator+=(CustomerOrder&&);				//Move a CustomerOrder into the orders queue

};