/* -------------------------------------------
Name: Jihyun Yoon
Student number:124558172
Email: nickyoon89@gmail.com
Section:
Date: 2017 Oct 23
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


int main (void)	
{
    // Declare variables here:
	struct Name uName;
	struct Address uAddress;
	struct Numbers uNumbers;
	char choice;

    // Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

    // Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%s",uName.firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	do { scanf("%c", &choice); } while (choice=='\n');
	if (choice != 'n') {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%s", uName.middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf("%s", uName.lastName);

    // Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d", &uAddress.streetNumber);
	printf("Please enter the contact's street name: ");
	scanf("%s", uAddress.street);
	printf("Do you want to enter an appartment number? (y or n): ");
	do { scanf("%c", &choice); } while (choice=='\n');
	if (choice != 'n') {
		printf("Please enter the contact's appartment number: ");
		scanf("%d", &uAddress.apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	fgets(uAddress.postalCode, sizeof(uAddress.postalCode), stdin); //to deal with \n from before
	fgets(uAddress.postalCode, sizeof(uAddress.postalCode), stdin);
	printf("Please enter the contact's city: ");
	scanf("%s", uAddress.city);


    // Contact Numbers Input:
	printf("Do you want to enter a cell phone number? (y or n): ");
	do { scanf("%c", &choice); } while (choice=='\n');
	if (choice != 'n') {
		printf("Please enter the contact's cell phone number: ");
		scanf("%s", uNumbers.cell);
	};
	printf("Do you want to enter a home phone number? (y or n): ");
	do { scanf("%c", &choice); } while (choice=='\n');
	if (choice != 'n') {
		printf("Please enter the contact's home phone number: ");
		scanf("%s", uNumbers.home);
	};
	printf("Do you want to enter a business phone number? (y or n): ");
	do { scanf("%c", &choice); } while (choice=='\n');
	if (choice != 'n') {
		printf("Please enter the contact's business phone number: ");
		scanf("%s", uNumbers.business);
	};


    // Display Contact Summary Details
	printf("\n");
	printf("Contact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", uName.firstName);
	printf("Middle initial(s): %s\n", uName.middleInitial);
	printf("Last name: %s\n\n", uName.lastName);

	printf("Address Details\n");
	printf("Street number: %d\n", uAddress.streetNumber);
	printf("Street name: %s\n", uAddress.street);
	printf("Apartment: %d\n", uAddress.apartmentNumber);
	printf("Postal code: %s\n", uAddress.postalCode);
	printf("City: %s\n\n", uAddress.city);

	printf("Phone Numbers:\n");
	printf("Cell phone number: %s\n", uNumbers.cell);
	printf("Home phone number: %s\n", uNumbers.home);
	printf("Business phone number: %s\n\n", uNumbers.business);


    // Display Completion Message
	printf("Structure test for Name, Address, and Numbers Done!\n");


    return 0;
}

/*  SAMPLE OUTPUT:
    
Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888

Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song

Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto

Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888

Structure test for Name, Address, and Numbers Done!
*/