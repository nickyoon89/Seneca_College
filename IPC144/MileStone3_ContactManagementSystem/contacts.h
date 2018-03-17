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

struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

struct Address {
	unsigned int streetNumber;
	char street[41];
	unsigned int apartmentNumber;
	char postalCode[8];
	char city[41];
};

struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};



//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name*);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address*);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers*);

// Get and store from standard input the values for a Contact (NOT: Contacts)
// NOTE:  Make sure the structure Contact does not have an 's' on the end!
// Put function prototype below:
void getContact(struct Contact *);
