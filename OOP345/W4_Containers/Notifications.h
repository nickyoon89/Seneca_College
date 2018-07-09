// Workshop 4 - Containers
// Notification.h
// Jihyun Yoon(Nick)
// 124558172
// 2018-06-09
#include "Message.h"
#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H
namespace sict {
	class Notifications {
		Message* msg;
		int size = 0;
	public:
		//default constructor
		Notifications();
		//reading-file constructor. It will check how many line in the file and save it in Message array.
		Notifications(std::ifstream&);
		//move constructor
		Notifications(Notifications&&);
		//move assignemtnt
		Notifications& operator=(Notifications&&);
		//destructor
		~Notifications();
		//show the contents 
		void display(std::ostream& os) const;
		//deleting copy assignment and constructor
		Notifications& operator=(Notifications&)=delete;
		Notifications(Notifications&) = delete;
	};
	//this function return the number of line of the parameter file.
	int getFileLine(std::ifstream& fin);
}
#endif // !SICT_NOTIFICATIONS_H
