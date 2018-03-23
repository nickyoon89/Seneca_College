// TODO: add file header comments here
/**********************************************************
// Workshop 7: Derived Class
// SuperHero.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/03/21                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include "SuperHero.h"

namespace sict {
	SuperHero::SuperHero() : Hero(){
		_bonus = 0;
		_defend = 0;
	}
	SuperHero::SuperHero(const char* name, unsigned int health, unsigned int strength, unsigned int bonus, unsigned int defend) : Hero(name, health, strength){
		if (bonus > 0 && defend > 0) {
			_bonus = bonus;
			_defend = defend;
		}
		else {
			_bonus = 0;
			_defend = 0;
		}
	}

	bool SuperHero::isEmpty() const {
		return (Hero::isEmpty() && _bonus == 0 && _defend == 0);
	}

	int SuperHero::attackStrength() const {
		if (isEmpty()) return 0;
		else return Hero::attackStrength()+_bonus;
	}

	int SuperHero::defend() const {
		if (isEmpty()) return 0;
		else return _defend;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		bool leftWin = true;
		int round;
		SuperHero firstHero = first;
		SuperHero secondHero = second;
		for (round = 0; round < max_rounds; round++)
		{
			firstHero -= (secondHero.attackStrength()-firstHero.defend());
			secondHero -= (firstHero.attackStrength()-secondHero.defend());
			if (!secondHero.isAlive()) { break; }
			else if (!firstHero.isAlive()) { leftWin = false; break; }
		}
		std::cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
		if (leftWin) std::cout << first;
		else std::cout << second;
		std::cout << " in " << round + 1 << " rounds." << std::endl;
		if (leftWin) return first;
		else return second;
	}
}