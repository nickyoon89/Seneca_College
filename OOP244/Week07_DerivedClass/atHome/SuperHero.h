// TODO: add file header comments here
/**********************************************************
// Workshop 7: Derived Class
// SuperHero.h
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/03/21                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict {
	class SuperHero :public Hero {
		unsigned int _bonus;
		unsigned int _defend;
	public:
		SuperHero();
		SuperHero(const char* name, unsigned int health, unsigned int strength, unsigned int bonus, unsigned int defend);
		bool isEmpty() const;
		int attackStrength() const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif // !SICT_HERO_H
