// OOP244 Workshop 7: Derived Classes
// File w7_at_home.cpp
// Version 2.0
// Date 2017/11/23
// Author       Hasan Murtaza, Chris Szalwinski
// Description
// This file is the client module for Workshop 7
/////////////////////////////////////////////////////

#include <iostream>
#include "Hero.h"
#include "SuperHero.h"

using namespace std;
using namespace sict;

void line(int width) {
	cout.width(width - 1);
	cout.fill('-');
	cout << '-';
	cout.fill(' ');
}

int main() {
  line(60);
  
  cout << endl << "Greek Heroes";
  Hero hercules         ("Hercules",  32, 4);
  Hero theseus          ("Theseus",   14, 5);
  Hero oddyseus         ("Odysseus",  15, 3);
  Hero ajax             ("Ajax",      17, 5);
  Hero achilles         ("Achilles",  20, 6);
  Hero hector           ("Hector",    30, 5);
  Hero atalanta         ("Atalanta",  10, 3);
  Hero hippolyta        ("Hippolyta", 10, 2);  
 
  cout << endl << "Quarter Finals" << endl;
  const Hero& greek_winner1 = achilles * hector; 
  const Hero& greek_winner2 = hercules * theseus;
  const Hero& greek_winner3 = oddyseus * ajax;
  const Hero& greek_winner4 = atalanta * hippolyta;
  
  cout << endl << "Semi Finals" << endl;
  const Hero& greek_winner_semifinal1 = greek_winner1  * greek_winner2;
  const Hero& greek_winner_semifinal2 = greek_winner3  * greek_winner4;

  cout << endl << "Finals" << endl;
  const Hero& greek_final = greek_winner_semifinal1 * greek_winner_semifinal2;

  line(60);
  cout << endl << "Comic book SuperHeros"; 
  
  SuperHero superman    ("Superman",      50, 9, 1, 9) ;
  SuperHero hulk        ("The_Hulk",      70, 6, 14, 3) ;
  SuperHero wonderwoman ("WonderWoman",   80, 5, 10, 10) ;
  SuperHero raven       ("Raven",         30, 10, 2, 5) ;
  
  cout << endl << "Semi Finals" << endl;
  const SuperHero& comic_winner1 = superman * hulk;
  const SuperHero& comic_winner2 = wonderwoman * raven;

  cout << endl << "Finals" << endl;
  const SuperHero& comic_final = comic_winner1 * comic_winner2;

  line(60);
  cout << endl << "Best Greeks Hero vs Best Comic Book SuperHero" << endl;
  greek_final * comic_final;
}
