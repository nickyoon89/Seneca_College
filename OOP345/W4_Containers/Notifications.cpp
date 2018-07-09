// Workshop 4 - Containers
// Notification.cpp
// Jihyun Yoon(Nick)
// 124558172
// 2018-06-09
#include <fstream>
#include <string>
#include <iostream>
#include "Message.h"
#include "Notifications.h"

namespace sict {
	//default constructor
	Notifications::Notifications() {
		msg = nullptr;
	}
	//reading-file constructor. It will check how many line in the file and save it in Message array.
	Notifications::Notifications(std::ifstream& fs){
		if (fs.good()) {
			size = getFileLine(fs);
			fs.clear();
			fs.seekg(0, std::ios::beg);
			if (size > 10) size = 10;
			msg = new Message[size];
			for (int i = 0; i < size; i++)
			{
				msg[i] = Message(fs,' ');
			}
		}
		else {
			msg = nullptr;
		}
	}
	//move constructor
	Notifications::Notifications(Notifications&& n){
		*this = std::move(n);
	}
	//move assignemtnt
	Notifications& Notifications::operator=(Notifications&& n){
		if (this != &n) {
			delete[] msg;
			msg = n.msg;
			size = n.size;
			n.msg = nullptr;
		}
		return *this;
	}
	//destructor
	Notifications::~Notifications(){
		delete[] msg;
		msg = nullptr;
	}
	//show the contents
	void Notifications::display(std::ostream& os) const{
		for (int i = 0; i < size; i++)
		{
			msg[i].display(os);
		}
	}
	//this function return the number of line of the parameter file.
	int getFileLine(std::ifstream& fin) {
		std::string temp;
		int numberOfLines = 0;
		while (std::getline(fin, temp))
		{
			numberOfLines++;
		}
		return numberOfLines;

	}
}