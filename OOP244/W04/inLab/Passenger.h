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
// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger
	{
	public:
		Passenger();
		Passenger(const char* name, const char* dest);
		bool isEmpty() const;
		void display() const;
	private:
		char p_name[ARRAY_MAX];
		char p_dest[ARRAY_MAX];
	};
}
#endif // !SICT_PASSENGER_H



