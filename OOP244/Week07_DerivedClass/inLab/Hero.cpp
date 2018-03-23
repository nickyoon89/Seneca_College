// TODO: add file header comments here
/**********************************************************
// Workshop 7: Derived Class
// Hero.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/03/20                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#include <iostream>
#include <cstring>
#include "Hero.h"

namespace sict {
	Hero::Hero() {
		_name[0] = '\0';
		_health = 0;
		_strength = 0;
	}
	Hero::Hero(const char* name, unsigned int health, unsigned int strength){
		if (name[0] != '\0'&&health > 0 && strength > 0) {
			strcpy(_name, name);
			_health = health;
			_strength = strength;
		}
		else {
			*this = Hero();
		}
	}
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			unsigned int takenAttack = attack;
			if (takenAttack > _health) {
				_health = 0;
			}
			else {
				_health -= takenAttack;
			}
		}
	}
	bool Hero::isAlive() const {
		return (_health > 0);
	}
	bool Hero::isEmpty() const {
		return (_name[0] == '\0'&&_health == 0 && _strength == 0);
	}
	int Hero::attackStrength() const {
		if (isEmpty()) return 0;
		else return _strength;
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		if (hero.isEmpty()) os << "No hero";
		else os << hero._name;
		return os;
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		bool leftWin = true;
		int round;
		Hero firstHero = first;
		Hero secondHero = second;
		for (round = 0; round < max_rounds; round++)
		{
			firstHero -= secondHero.attackStrength();
			secondHero -= firstHero.attackStrength();
			if (!secondHero.isAlive()) { break; }
			else if (!firstHero.isAlive()) { leftWin = false; break; }
		}
		std::cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";
		if (leftWin) std::cout << first;
		else std::cout << second;
		std::cout << " in " << round + 1 << " rounds." << std::endl;
		if (leftWin) return first;
		else return second;
	}
}