#pragma once
#include <iostream>
#include <iomanip>

const unsigned int CODE_WIDTH = 5;

class Item
{
	std::string name;
	unsigned serialNumber;
	unsigned int Quantity;
	std::string description;
	unsigned int field_width;

public:
	Item(std::string& record);						//takes a record from the items file and parses the data

	const std::string& getName() const;				//Returns a reference to the items name
	const unsigned int getSerialNumber();			//Returns a reference to the serial number
	const unsigned int getQuantity();				//Returns a reference to the remaining quantity
	void updateQuantity();							//Removes 1 from the quantity
	void display(std::ostream&, bool) const;
};