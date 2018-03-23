// TODO: add file header comments here
/**********************************************************
// Workshop 7: Derived Class
// Hero.h
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/03/20                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict {
	int const max_rounds = 100;
	class Hero {
		char _name[41];
		unsigned int _health;
		unsigned int _strength;
	public:
		Hero();
		Hero(const char* name, unsigned int health, unsigned int strength);
		void operator-=(int attack);
		bool isAlive() const;
		bool isEmpty() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};	
	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif // !SICT_HERO_H
