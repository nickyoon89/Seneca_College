/**********************************************************
// OOP244 Workshop 9
// File: Data.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/04/03                       file made
///////////////////////////////////////////////////////////
**********************************************************/

#include "Data.h"

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"

		std::cout.precision(2);
		std::cout << "Population change from "<<min(year,n)<<" to "<< max(year, n) <<" is "<<std::fixed<<static_cast<double>(population[n-1] - population[0])/ 1000000 <<" million" << std::endl;
		
		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		std::cout << "Violent Crime trend is ";
		if (violentCrimeRate[1] - violentCrimeRate[0] > 0) std::cout << "up";
		else std::cout << "down";
		std::cout << std::endl;


		// Q3 print the GTA number accurate to 0 decimal places
		std::cout << "There are "<< std::fixed << average(grandTheftAuto,n)/1000000 <<" million Grand Theft Auto incidents on average a year" << std::endl;



		// Q4. Print the min and max violentCrime rates
		std::cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate,n)) << std::endl;
		std::cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) <<std::endl;


	}
}