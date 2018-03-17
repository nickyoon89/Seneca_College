/*
+--------------------------------------------------------*
|              2  0  1  7  ~  F  A  L  L
|                 I  P  C  :  1  4  4
|                 ASSIGNMENT #2 MS# 2
|
|   S  E  N  E  C  A               C  O  L  L  E  G  E
|   ========  =======  =====  ========  ======  ======
|      ==     ==      ==        ==     ==      ==   ==
|     ==     ====     ====     ==     ====    ======
|    ==     ==          ==    ==     ==      == ==
|   ==     ======  =====     ==     ======  ==   ==
|                                                         
|  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
|  !!!   DO NOT ALTER THE CONTENTS OF THIS FILE   !!!
|  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
+--------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void printSectionHeader(const char*);

int main(void)
{
    struct Contact contact = { { {'\0'} } }; //,'\0','\0'}, {0,'\0',0,'\0','\0'}, {'\0','\0','\0'} };
    int tstInteger;
    
    //--------------------------------------------------------
    printSectionHeader("Yes()");
    printf("Please enter 'Y' > ");
    printf("    Result: %d\n", yes() );
    printf("Please enter 'y' > ");
    printf("    Result: %d\n", yes());
    printf("Please enter 'N' > ");
    printf("    Result: %d\n", yes());
    printf("Please enter 'yes', then 'no', then 'n' > ");
    printf("    Result: %d\n", yes());

    //--------------------------------------------------------
    printSectionHeader("pause()");
    pause();

    //--------------------------------------------------------
    printSectionHeader("getInt()");
    printf("Enter 'ipc', then '144' > ");
    tstInteger = getInt();
    printf("Integer entered: %d\n", tstInteger);

    //--------------------------------------------------------
    printSectionHeader("getIntInRange(int,int)");
    printf("Enter 'seneca', then '99', then '501', then '250' > ");
    tstInteger = getIntInRange(100, 500);
    printf("Integer entered: %d\n", tstInteger);

    //--------------------------------------------------------
    printSectionHeader("getContact(struct Contact *)");
    getContact(&contact);
    printf("\nValues Entered:\n");
    printf("Name: %s %s %s\n", contact.name.firstName, contact.name.middleInitial, contact.name.lastName);
    printf("Address: %d|%s|%d|%s|%s\n", contact.address.streetNumber, contact.address.street, 
	contact.address.apartmentNumber, contact.address.postalCode, contact.address.city);
    printf("Numbers: %s|%s|%s\n", contact.numbers.cell, contact.numbers.home, contact.numbers.business);

    //--------------------------------------------------------
    printSectionHeader("ContactManagerSystem()");
    ContactManagerSystem();

    //--------------------------------------------------------
    printSectionHeader("Assign#2 - MS #2 test completed");

    return 0;
}

// Display specified test section header
void printSectionHeader(const char* testName)
{
    printf("\n");
    printf("------------------------------------------\n");
    printf("Testing: %s\n", testName);
    printf("------------------------------------------\n");
}

/*
EXPECTED OUTPUT:
------------------------------------------
Testing: Yes()
------------------------------------------
Please enter 'Y' > Y
Result: 1
Please enter 'y' > y
Result: 1
Please enter 'N' > N
Result: 0
Please enter 'yes', then 'no', then 'n' > yes
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: no
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: n
Result: 0

------------------------------------------
Testing: pause()
------------------------------------------
(Press Enter to Continue)

------------------------------------------
Testing: getInt()
------------------------------------------
Enter 'ipc', then '144' > ipc
*** INVALID INTEGER *** <Please enter an integer>: 144

------------------------------------------
Testing: getIntInRange(int,int)
------------------------------------------
Enter 'seneca', then '99', then '501', then '250' > seneca
*** INVALID INTEGER *** <Please enter an integer>: 99
*** OUT OF RANGE *** <Enter a number between 100 and 500>: 501
*** OUT OF RANGE *** <Enter a number between 100 and 500>: 250

------------------------------------------
Testing: getContact(struct Contact *)
------------------------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): yes
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: one two
*** INVALID INTEGER *** <Please enter an integer>: 99
Please enter the contact's street name: Keele Street
Do you want to enter an apartment number? (y or n): no
*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: n
Please enter the contact's postal code: A8A 3J3
Please enter the contact's city: Toronto
Please enter the contact's cell phone number: 9051116666
Do you want to enter a home phone number? (y or n): n
Do you want to enter a business phone number? (y or n): n

Values Entered:
Name: Tom Wong Song
Address: 99|Keele Street|0|A8A 3J3|Toronto
Numbers: 9051116666||

------------------------------------------
Testing: ContactManagerSystem()
------------------------------------------
Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 9
*** OUT OF RANGE *** <Enter a number between 0 and 6>: 1

<<< Feature 1 is unavailable >>>

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 4

<<< Feature 4 is unavailable >>>

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 6

<<< Feature 6 is unavailable >>>

(Press Enter to Continue)

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 0

Exit the program? (Y)es/(N)o: n

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 0

Exit the program? (Y)es/(N)o: y

Contact Management System: terminated

------------------------------------------
Testing: Assign#2 - MS #2 test completed
------------------------------------------
*/
