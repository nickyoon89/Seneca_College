// TODO: add file header comments here
/**********************************************************
// Workshop 3: Classes and Privacy
// Passenger.h
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/02/13                       file made
///////////////////////////////////////////////////////////
**********************************************************/

// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define ARRAY_MAX 32

#include <iomanip>
#include <cstring>
#include <iostream>
// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger
	{
	public:
		Passenger();
		Passenger(const char* name, const char* dest);
		Passenger(const char* name, const char* dest, int yrs, int mths, int day);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger& passenger) const;
	private:
		char p_name[ARRAY_MAX];
		char p_dest[ARRAY_MAX];
		int p_dprt_yrs;
		int p_dprt_mths;
		int p_dprt_day;
	};
}
#endif // !SICT_PASSENGER_H



