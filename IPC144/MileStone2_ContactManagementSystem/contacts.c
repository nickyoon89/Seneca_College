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
#include "contacts.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:



// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name* uName) {
	char choice;
	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%s", uName->firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	do { scanf("%c", &choice); } while (choice == '\n');
	if (choice != 'n') {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", uName->middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf("%s", uName->lastName);
}



// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address* uAddress) {
	char choice;
	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d", &uAddress->streetNumber);
	printf("Please enter the contact's street name: ");
	scanf("%s", uAddress->street);
	printf("Do you want to enter an apartment number? (y or n): ");
	do { scanf("%c", &choice); } while (choice == '\n');
	if (choice != 'n') {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &uAddress->apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	fgets(uAddress->postalCode, sizeof(uAddress->postalCode), stdin); //to deal with \n from before
	fgets(uAddress->postalCode, sizeof(uAddress->postalCode), stdin);
	printf("Please enter the contact's city: ");
	scanf("%s", uAddress->city);
}




// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers* uNumbers) {
	char choice;
	// Contact Numbers Input:
	printf("Do you want to enter a cell phone number? (y or n): ");
	do { scanf("%c", &choice); } while (choice == '\n');
	if (choice != 'n') {
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", uNumbers->cell);
	};
	printf("Do you want to enter a home phone number? (y or n): ");
	do { scanf("%c", &choice); } while (choice == '\n');
	if (choice != 'n') {
		printf("Please enter the contact's home phone number: ");
		scanf("%s", uNumbers->home);
	};
	printf("Do you want to enter a business phone number? (y or n): ");
	do { scanf("%c", &choice); } while (choice == '\n');
	if (choice != 'n') {
		printf("Please enter the contact's business phone number: ");
		scanf("%s", uNumbers->business);
	};
}

