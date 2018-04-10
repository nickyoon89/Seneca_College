// Workshop 9 - Function Templates
// File: ws9_lab.cpp
// Version: 2.0
// Date: 2017/12/15
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file implements the application
///////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "Data.h"

using namespace std;
using namespace sict;

//////////////////
// File format:
// - first line is number of columns
// - each record is Name, data1, data2, data3 ,...

// file crimedata.csv
/* 
5
Year,2000,2001,2002,2003,2004
Population,281421906,285317559,287973924,290788976,293656842
ViolentCrime,1425486,1439480,1423677,1383676,1360088
ViolentCrime_Rate,506.5,504.5,494.4,475.8,463.2
GrandTheftAuto,1160002,1228391,1246646,1261226,1237851
GrandTheftAuto_Rate,412.2,430.5,432.9,433.7,421.5

*/

// main answers questions about the data in file crimedata.csv
// - reads the first line with the number of data items
// - allocates memory for the data values in each file record
// - reads the data for each record
//   - ensures that it is reading the correct row. If the name
//     does not match the row, return false and exits prematurely
// - displays the data for each record
// - answers questions about the data
// - deallocates the memory
//
int main() {
    
    ifstream finput ("w9_prof_crimedata.csv");
    if (!finput) {
        cerr << "Cannot open file w9_prof_crimedata.csv" << endl;
        return 1;
    }
    
    // file format
    // -------------
    // n
    int n = 0;
    finput >> n;
    finput.ignore(2000, '\n');  // read the rest of the line
    
    // allocate memory for n items
    int*    year               = new int[n];
    int*    population         = new int[n];     
    int*    violentCrime       = new int[n];    
    double* violentCrimeRate   = new double[n]; 
    int*    grandTheftAuto     = new int[n];   
    double* grandTheftAutoRate = new double[n]; 
    
    ////////////////////
    // Note: this is a simple file reader
    // - read each row in the same order it is found in the file
    //
    if (!readRow(finput, "Year",                 year, n))              { return 1; }
    if (!readRow(finput, "Population",           population, n))        { return 1; }
    if (!readRow(finput, "ViolentCrime",         violentCrime, n))      { return 1; }
    if (!readRow(finput, "ViolentCrime_Rate",    violentCrimeRate, n))  { return 1; }
    if (!readRow(finput, "GrandTheftAuto",       grandTheftAuto, n))    { return 1; }
    if (!readRow(finput, "GrandTheftAuto_Rate",  grandTheftAutoRate, n)){ return 1; }

    // display the data
    display("Year", year, n);
    display("Population", population, n);
    display("ViolentCrime", violentCrime, n);
    display("ViolentCrimeRate", violentCrimeRate, n);
    display("GrandTheftAuto", grandTheftAuto, n);
    display("GrandTheftAutoRate", grandTheftAutoRate, n);
    cout << endl;
    
    // Answer the validation questions
	answers(year, population, violentCrime, violentCrimeRate, grandTheftAuto, n);
    
	// deallocate memory
	delete[] year;
	delete[] population;
	delete[] violentCrime;
	delete[] violentCrimeRate;
	delete[] grandTheftAuto;
	delete[] grandTheftAutoRate;

	// execution successful
	return 0;
}
