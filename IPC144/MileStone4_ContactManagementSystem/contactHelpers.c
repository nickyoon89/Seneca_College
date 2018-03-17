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

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// clearKeyboard definition goes here
void clearKeyboard(void)
{
	while (getchar() != '\n')
		;  // empty statement intentional
}

// pause definition goes here
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
	printf("\n");
}


// getInt definition goes here
int getInt(void)
{
	char nl;
	int value;
	scanf("%d%c", &value, &nl);
	if (nl != '\n')
	{
		clearKeyboard();
	}
	while (nl != '\n') {
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &value, &nl);
		if (nl != '\n')
		{
			clearKeyboard();
		}
	};
	return value;
}


// getIntInRange definition goes here
int getIntInRange(int min, int max)
{
	int intInRange;
	do {
		intInRange = getInt();
		if (intInRange > max || intInRange < min) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	} while (intInRange > max || intInRange < min);
	return intInRange;
}


// yes definition goes here
int yes(void)
{
	char yn;
	char nl;
	scanf("%c%c", &yn, &nl);
	if (nl != '\n')
	{
		clearKeyboard();
	}

	while ((yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n') || (nl != '\n')) {
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &yn, &nl);
		if (nl != '\n')
		{
			clearKeyboard();
		}
	}
	if (yn == 'Y' || yn == 'y') return 1;
	else return 0;
}


// menu definition goes here
int menu(void)
{
	int menu;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	do {
		menu = getInt();
		if (menu > 6 || menu < 0) {
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
		}
	} while (menu > 6 || menu < 0);
	return menu;
}


// ContactManagerSystem definition goes here
void ContactManagerSystem(void)
{
	struct Contact uContacts[MAXCONTACTS] = 
	{ { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
 {
	 { "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
 {
	 { "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
 {
	 { "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};
	int selection;
	int yn = 0;
	while (yn == 0) {
		selection = menu();
		switch (selection)
		{
		case 1:
			displayContacts(uContacts,MAXCONTACTS);
			pause();
			break;
		case 2:
			addContact(uContacts, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(uContacts, MAXCONTACTS);
			pause();
			break;
		case 4:
			deleteContact(uContacts, MAXCONTACTS);
			pause();
			break;
		case 5:
			searchContacts(uContacts, MAXCONTACTS);
			pause();
			break;
		case 6:
			sortContacts(uContacts, MAXCONTACTS);
			pause();
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			yn = yes();
			printf("\n");
			if (yn)printf("Contact Management System: terminated\n");
			break;
		default:
			break;
		}
	}
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[]) {
	scanf("%s", telNum);
	clearKeyboard();
	while(strlen(telNum)!=10){
		printf("Enter a 10-digit phone number: ");
		scanf("%s", telNum);
		clearKeyboard();
	}
}

// findContactIndex:
int findContactIndex(const struct Contact uContacts[], int size, const char number[]) {
	int i;
	for (i = 0; i < size; i++)
	{
		if (strcmp(uContacts[i].numbers.cell,number)==0) {
			return i;
		}
	}
	return -1;
}

// displayContactHeader:
void displayContactHeader(void) {
	printf("\n");
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter:
void displayContactFooter(int total) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", total);
}

// displayContact:
void displayContact(const struct Contact* uContact) {
	printf(" %s ", uContact->name.firstName);
	if(strlen(uContact->name.middleInitial)!=0) printf("%s ", uContact->name.middleInitial);
	printf("%s\n", uContact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", uContact->numbers.cell, uContact->numbers.home, uContact->numbers.business);
	printf("       %d %s, ",uContact->address.streetNumber, uContact->address.street);
	if(uContact->address.apartmentNumber>0) printf("Apt# %d, ", uContact->address.apartmentNumber);
	printf("%s, %s\n", uContact->address.city, uContact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact uContacts[], int size) {
	int i;
	int count=0;
	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if (strlen(uContacts[i].numbers.cell) != 0)
		{
			displayContact(&uContacts[i]);
			count++;
		}
	}
	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact uContacts[], int size) {
	char cellnumb[11];
	int foundIndex;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellnumb);
	foundIndex = findContactIndex(uContacts, sizeof(uContacts), cellnumb);
	if (foundIndex == -1) {
		printf("*** Contact	NOT FOUND ***\n");
	}
	else {
		printf("\n");
		displayContact(&uContacts[foundIndex]);
		printf("\n");
	}
}

// addContact:
void addContact(struct Contact uContacts[], int size) {
	int i;
	for (i = 0; i < size; i++)
	{
		if (strlen(uContacts[i].numbers.cell) == 0) {
			break;
		}
	}
	if (i == size) printf("\n*** ERROR: The contact list is full! ***\n");
	else {
		printf("\n");
		getContact(&uContacts[i]);
		printf("--- New contact added! ---\n");
	}
}

// updateContact:
void updateContact(struct Contact uContacts[], int size) {
	char phoneNumb[11];
	int foundIndex;
	int yn;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNumb);
	foundIndex = findContactIndex(uContacts, sizeof(uContacts), phoneNumb);
	if (foundIndex == -1) printf("*** Contact NOT FOUND ***\n");
	else {
		printf("\nContact found:\n");
		displayContact(&uContacts[foundIndex]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		yn = yes();
		if (yn == 1) getName(&uContacts[foundIndex].name);
		printf("Do you want to update the address? (y or n): ");
		yn = yes();
		if (yn == 1) getAddress(&uContacts[foundIndex].address);
		printf("Do you want to update the numbers? (y or n): ");
		yn = yes();
		if (yn == 1) getNumbers(&uContacts[foundIndex].numbers);
		printf("--- Contact Updated! ---\n");
	}
}

// deleteContact:
void deleteContact(struct Contact uContacts[], int size) {
	char phoneNumb[11];
	int foundIndex;
	int yn;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNumb);
	foundIndex = findContactIndex(uContacts, sizeof(uContacts), phoneNumb);
	if (foundIndex == -1) printf("*** Contact NOT FOUND ***\n");
	else {
		printf("\nContact found:\n");
		displayContact(&uContacts[foundIndex]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		yn = yes();
		if (yn == 1) 
		{
			uContacts[foundIndex].numbers.business[0] = '\0';
			uContacts[foundIndex].numbers.cell[0] = '\0';
			uContacts[foundIndex].numbers.home[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}		
	}
}

// sortContacts:
void sortContacts(struct Contact uContact[], int size) {
	int i;
	int j;
	struct Contact temp;
	for (i = 0; i < size-1; i++)
	{
		for (j = i+1; j  < size; j ++)
		{
			if (strlen(uContact[i].numbers.cell) != 0 && strlen(uContact[j].numbers.cell) != 0) {
				if (strcmp(uContact[i].numbers.cell, uContact[j].numbers.cell) > 0) {
					temp = uContact[i];
					uContact[i] = uContact[j];
					uContact[j] = temp;
				}
			}
		}
	}
	printf("\n--- Contacts sorted! ---\n");
}