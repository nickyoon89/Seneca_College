// TODO: add file header comments here
/**********************************************************
// Workshop 6: Class with a Resource
// Contact.h
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/03/13                       file made
// Jihyun        2018/03/16                       atHome part
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
	class Contact
	{
		char _names[20];
		long long* _phones;
		int _storedNo;
	public:
		Contact();
		Contact(const char*, const long long*, int);
		Contact(const Contact&);
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact& operator=(const Contact& cont);
		Contact& operator+=(long long phoneNum);
	};
}

#endif // !CONTACT_H
