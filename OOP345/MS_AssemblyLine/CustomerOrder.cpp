#include "CustomerOrder.h"
#include "Utilities.h"
#include "Item.h"

CustomerOrder::CustomerOrder() {
	Name = "";
	Product = "";
	ItemCount = 0u;
	ItemList = nullptr;
	field_width = 0u;
}
CustomerOrder::CustomerOrder(std::string& record) {
	bool more = true;
	size_t pos = 0u;
	size_t count = 0u;
	size_t itemPos = 0u;
	size_t itemCnt = 0u;
	Utilities util;
	util.setFieldWidth(field_width);
	while (more) {
		if (count == 0) Name = util.extractToken(record, pos, more);
		else if (count == 1) Product = util.extractToken(record, pos, more);
		else if (count == 2) {
			itemPos = pos;
			while (more) {
				util.extractToken(record, itemPos, more);
				itemCnt++;
			}
			ItemCount = itemCnt;
			itemCnt = 0;
			more = true;
			ItemList = new ItemInfo*[ItemCount];
		}
		else {
			ItemList[itemCnt] = new ItemInfo(util.extractToken(record, pos, more));
			itemCnt++;
		}
		count++;
	}
}
CustomerOrder::~CustomerOrder() {
	for (size_t i = 0u; i < ItemCount; i++) delete ItemList[i];
	delete[] ItemList;
}

//Object move functionality
CustomerOrder::CustomerOrder(CustomerOrder&& ref) {
	*this = std::move(ref);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& ref) {
	if (this != &ref) {
		if (ItemList != nullptr) {
			for (size_t i = 0u; i < ItemCount; i++) delete ItemList[i];
			delete[] ItemList;
		}
		Name = ref.Name;
		Product = ref.Product;
		ItemCount = ref.ItemCount;
		ItemList = ref.ItemList;
		field_width = ref.field_width;
		ref.Name = "";
		ref.Product = "";
		ref.ItemCount = 0;
		ref.ItemList = nullptr;
		ref.field_width = 0;
	}
	return *this;
}

//Returns true if order completely filled, false otherwise
bool CustomerOrder::getOrderFillState() {
	for (size_t i = 0u; i < ItemCount; i++) {
		if (ItemList[i]->FillState == false) return false;
	}
	return true;
}
//Returns true if the given item has been filled
bool CustomerOrder::getItemFillState(std::string s) {
	bool ret = true;
	for (size_t i = 0u; i < ItemCount; i++) {
		if (ItemList[i]->ItemName == s) ret = ItemList[i]->FillState;
		if (ret == false) break;
	}
	return ret;
}					
//Fills the customer order item if the inventory on Item is available
void CustomerOrder::fillItem(Item& item_, std::ostream& os) {
	size_t i;
	for (i = 0; i < ItemCount; i++) {
		if (ItemList[i]->ItemName == item_.getName() && ItemList[i]->FillState==false) {
			ItemList[i]->FillState = true;
			ItemList[i]->SerialNumber = item_.getSerialNumber();
			os << (ItemList[i]->FillState ? "Filled" : "UnFilled") <<
				" " << this->Name << ", " << this->Product << "[" << ItemList[i]->ItemName << "]" << std::endl;
		}		
	}
}					
//Displays the details of the CustomerOrder to the ostream object provided
void CustomerOrder::Display(std::ostream& os) {
	os << Name << std::endl;
	os << Product << std::endl;
	for (size_t i = 0u; i < ItemCount; i++) {
		os << "[" << ItemList[i]->SerialNumber << "]" << ItemList[i]->ItemName << " - "
			<< (ItemList[i]->FillState ? "FILLED" : "MISSING") << std::endl;
	}

}							