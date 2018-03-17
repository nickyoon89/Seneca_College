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
	char cell[21];
	char home[21];
	char business[21];
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
