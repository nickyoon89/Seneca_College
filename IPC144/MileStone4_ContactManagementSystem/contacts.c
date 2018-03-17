/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include <stdio.h>
#include "contactHelpers.h"
#include <string.h>


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+
// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name* uName) {
	int choice;
	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	fgets(uName->firstName, sizeof(uName->firstName), stdin);
	if (uName->firstName[strlen(uName->firstName) - 1] == '\n')
		uName->firstName[strlen(uName->firstName) - 1] = '\0';
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	choice = yes();
	if (choice != 0) {
		printf("Please enter the contact's middle initial(s): ");
		fgets(uName->middleInitial, sizeof(uName->middleInitial), stdin);
		if (uName->middleInitial[strlen(uName->middleInitial) - 1] == '\n')
			uName->middleInitial[strlen(uName->middleInitial) - 1] = '\0';
	}
	else uName->middleInitial[0] = '\0';
	printf("Please enter the contact's last name: ");
	fgets(uName->lastName, sizeof(uName->lastName), stdin);
	if (uName->lastName[strlen(uName->lastName) - 1] == '\n')
		uName->lastName[strlen(uName->lastName) - 1] = '\0';
}



// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address* uAddress) {
	int choice;
	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	uAddress->streetNumber = getInt();
	printf("Please enter the contact's street name: ");
	fgets(uAddress->street, sizeof(uAddress->street), stdin);
	if (uAddress->street[strlen(uAddress->street) - 1] == '\n')
		uAddress->street[strlen(uAddress->street) - 1] = '\0';
	printf("Do you want to enter an apartment number? (y or n): ");
	choice = yes();
	if (choice != 0) {
		printf("Please enter the contact's apartment number: ");
		uAddress->apartmentNumber = getInt();
	}
	else uAddress->apartmentNumber = '\0';
	printf("Please enter the contact's postal code: ");
	fgets(uAddress->postalCode, sizeof(uAddress->postalCode), stdin);
	if (uAddress->postalCode[strlen(uAddress->postalCode) - 1] == '\n')
		uAddress->postalCode[strlen(uAddress->postalCode) - 1] = '\0';
	else clearKeyboard();
	printf("Please enter the contact's city: ");
	fgets(uAddress->city, sizeof(uAddress->city), stdin);
	if (uAddress->city[strlen(uAddress->city) - 1] == '\n')
		uAddress->city[strlen(uAddress->city) - 1] = '\0';
}




// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers* uNumbers) {
	int choice;
	// Contact Numbers Input:
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(uNumbers->cell);
	printf("Do you want to enter a home phone number? (y or n): ");
	choice = yes();
	if (choice != 0) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(uNumbers->home);
	}
	else uNumbers->home[0] = '\0';
	printf("Do you want to enter a business phone number? (y or n): ");
	choice = yes();
	if (choice != 0) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(uNumbers->business);
	}
	else uNumbers->business[0] = '\0';
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* uContact)
{
	// Call the Contact function getName to store the values for the Name member
	getName(&uContact->name);
	// Call the Contact function getAddress to store the values for the Address member
	getAddress(&uContact->address);
	// Call the Contact function getNumbers to store the values for the Numbers member
	getNumbers(&uContact->numbers);

}

