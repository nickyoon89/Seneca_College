/* -------------------------------------------
Name:           
Student number: 
Email:          
Section:        
Date:           
----------------------------------------------
Assignment: 2
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:



//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

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
	while (nl != '\n'){
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
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ",min,max);
		}
	} while (intInRange > max || intInRange < min);
	return intInRange;
}


// yes definition goes here
int yes(void)
{
	char yn;
	char nl;
	scanf("%c%c",&yn,&nl);
	if (nl!='\n')
	{
		clearKeyboard();
	}

	while((yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n') || (nl != '\n')){
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
	int selection;
	int yn = 0;
	while (yn == 0) {
		selection = menu();
		switch (selection)
		{
		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			yn = yes();
			printf("\n");
			if(yn)printf("Contact Management System: terminated\n");
			break;
		default:
			break;
		}
	}
}