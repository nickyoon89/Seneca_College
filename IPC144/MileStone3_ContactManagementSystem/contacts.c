/* -------------------------------------------
Name:
Student number:
Email:
Section:
Date:
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contacts.h"
#include "contactHelpers.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:



// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name* uName) {
	int choice;
	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%s", uName->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	choice = yes();
	if (choice != 0) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", uName->middleInitial);
		clearKeyboard();
	}
	printf("Please enter the contact's last name: ");
	scanf("%s", uName->lastName);
	clearKeyboard();
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
	//uAddress->street[strcspn(uAddress->street, "\n")] = 0;
	if (uAddress->street[strlen(uAddress->street)-1] == '\n')
		uAddress->street[strlen(uAddress->street)-1] = '\0';
	printf("Do you want to enter an apartment number? (y or n): ");
	choice = yes();
	if (choice != 0) {
		printf("Please enter the contact's apartment number: ");
		uAddress->apartmentNumber = getInt();
	}
	printf("Please enter the contact's postal code: ");
	fgets(uAddress->postalCode, sizeof(uAddress->postalCode), stdin);
	if (uAddress->postalCode[strlen(uAddress->postalCode)-1] == '\n')
		uAddress->postalCode[strlen(uAddress->postalCode)-1] = '\0';
	//uAddress->postalCode[strcspn(uAddress->postalCode, "\n")] = 0;
	printf("Please enter the contact's city: ");
	scanf("%s", uAddress->city);
	clearKeyboard();
}




// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers* uNumbers) {
	int choice;
	// Contact Numbers Input:
	printf("Please enter the contact's cell phone number: ");
	scanf("%s", uNumbers->cell);
	clearKeyboard();
	printf("Do you want to enter a home phone number? (y or n): ");
	choice = yes();
	if (choice != 0) {
		printf("Please enter the contact's home phone number: ");
		scanf("%s", uNumbers->home);
		clearKeyboard();
	};
	printf("Do you want to enter a business phone number? (y or n): ");
	choice = yes();
	if (choice != 0) {
		printf("Please enter the contact's business phone number: ");
		scanf("%s", uNumbers->business);
		clearKeyboard();
	};
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
