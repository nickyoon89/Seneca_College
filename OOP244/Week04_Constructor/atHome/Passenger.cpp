// TODO: add file header comments here
/**********************************************************
// Workshop 3: Classes and Privacy
// Passenger.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/02/13                       file made
///////////////////////////////////////////////////////////
**********************************************************/

// TODO: add your headers here
#include "Passenger.h"
using namespace std;
// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger()
	{
		p_name[0] = '\0';
		p_dest[0] = '\0';
		p_dprt_yrs = 0;
		p_dprt_mths = 0;
		p_dprt_day = 0;
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* dest) {
		if (name != nullptr&&name[0] != '\0'&& dest != nullptr&&dest[0] != '\0') {
			strcpy(p_name, name);
			strcpy(p_dest, dest);
			p_dprt_yrs = 2017;
			p_dprt_mths = 7;
			p_dprt_day = 1;
		}
		else {
			*this = Passenger();
		}
	}
	Passenger::Passenger(const char* name, const char* dest, int yrs, int mths, int day)
	{
		if (name != nullptr&&name[0] != '\0'&& dest != nullptr&&dest[0] != '\0'&&yrs >= 2017 && yrs <= 2020 && mths >= 1 && mths <= 12 && day >= 1 && day <= 31) {
			strcpy(p_name, name);
			strcpy(p_dest, dest);
			p_dprt_yrs = yrs;
			p_dprt_mths = mths;
			p_dprt_day = day;
		}
		else {
			*this = Passenger();
		}
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if (p_name[0] == '\0'&&p_dest[0] == '\0'&&p_dprt_yrs == 0 && p_dprt_mths == 0 && p_dprt_day == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	const char* Passenger::name() const {
		if (isEmpty()) return "";
		else return p_name;
	}

	bool Passenger::canTravelWith(const Passenger& passenger) const {
		if (strcmp(p_dest, passenger.p_dest) == 0) {
			if (p_dprt_yrs == passenger.p_dprt_yrs) {
				if (p_dprt_mths == passenger.p_dprt_mths) {
					if (p_dprt_day == passenger.p_dprt_day) {
						return true;
					}
				}
			}
		}
		return false;
	}
	// TODO: implement display query here
	void Passenger::display() const {
		if (isEmpty()) cout << "No passenger!" << std::endl;
		else cout << p_name << " - " << p_dest << " on " << p_dprt_yrs << "/" << setfill('0') << setw(2) << p_dprt_mths << "/" << setfill('0') << setw(2) << p_dprt_day << endl;
	}
}