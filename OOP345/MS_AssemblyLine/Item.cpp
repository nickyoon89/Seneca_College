#include "Utilities.h"
#include "Item.h"

//takes a record from the items file and parses the data
Item::Item(std::string& record) {
	bool more = true;
	size_t pos = 0;
	size_t count = 0;
	Utilities util;
	util.setFieldWidth(field_width);
	while (more && count<4) {
		if (count == 0) name = util.extractToken(record, pos, more);
		else if (count == 1) serialNumber = (unsigned)std::stoi(util.extractToken(record, pos, more));
		else if (count == 2) Quantity = (unsigned int)std::stoi(util.extractToken(record, pos, more));
		else description = util.extractToken(record, pos, more);
		count++;
	}
}						
//Returns a reference to the items name
const std::string& Item::getName() const {
	return name;
}
//Returns a reference to the serial number
const unsigned int Item::getSerialNumber() {
	return serialNumber++;
}
//Returns a reference to the remaining quantity
const unsigned int Item::getQuantity() {
	return Quantity;
}
//Removes 1 from the quantity
void Item::updateQuantity() {
	if (getQuantity() > 0) {
		Quantity -= 1;
	}
}
void Item::display(std::ostream& os, bool full) const {
	os << std::setw(13) << std::left << std::fixed << name;
	os << "[" << serialNumber << "] Quantity " << Quantity << "   Description: " << description << std::endl;
}