/*
Name: Jihyun Yoon
Email: jyoon31@myseneca.ca
Student Number: 124558172
*/

#include <iostream>
#include "graph.h"
#include "tools.h"
using namespace std;

// SeneGraph program
int main() {
	int noOfSamples = 0;
	int samples[MAX_NO_OF_SAMPLES] = { 0 };
	bool done = false;
	cout << "Welcome to SeneGraph" << endl;
	while (!done) {
		cout << "No Of Samples: " << noOfSamples << endl;
		switch (sict::menu()) {
		case 1:
			cout << "Enter number of samples on hand: ";
			noOfSamples = sict::getInt(1, MAX_NO_OF_SAMPLES);
			break;
		case 2:
			if (noOfSamples == 0) {
				cout << "First enter the number of Samples." << endl;
			}
			else {
				cout << "Please enter the sample values: " << endl;
				sict::getSamples(samples, noOfSamples);
			}
			break;
		case 3:
			if (noOfSamples == 0) {
				cout << "First enter the number of Samples." << endl;
			}
			else if (samples[0] == 0) {
				cout << "Firt enter the samples." << endl;
			}
			else {
				sict::printGraph(samples, noOfSamples);
			}
			break;
		case 0:
			cout << "Thanks for using SeneGraph" << endl;
			done = true;
		}
	}
	return 0;
}
