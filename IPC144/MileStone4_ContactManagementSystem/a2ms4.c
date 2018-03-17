/*
+--------------------------------------------------------*
|              2  0  1  7  ~  F  A  L  L
|                 I  P  C  :  1  4  4
|                 ASSIGNMENT #2 MS# 4
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
    ContactManagerSystem();

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

Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Maggie R. Greene
    C: 9051112222   H: 9052223333   B: 9053334444
       55 Hightop House, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
+-----------------------------------------------------------------------------+
Total contacts: 4

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

Select an option:> 2

Please enter the contact's first name: I Should
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): B.
Please enter the contact's last name: Gone
Please enter the contact's street number: 99
Please enter the contact's street name: No Name Rd.
Do you want to enter an apartment number? (y or n): y
Please enter the contact's apartment number: 11
Please enter the contact's postal code: A1A J9J
Please enter the contact's city: Nowhere City
Please enter the contact's cell phone number: 1112223333
Do you want to enter a home phone number? (y or n): y
Please enter the contact's home phone number: 9991112222
Do you want to enter a business phone number? (y or n): n
--- New contact added! ---
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

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Maggie R. Greene
    C: 9051112222   H: 9052223333   B: 9053334444
       55 Hightop House, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should B. Gone
    C: 1112223333   H: 9991112222   B:
       99 No Name Rd., Apt# 11, Nowhere City, A1A J9J
+-----------------------------------------------------------------------------+
Total contacts: 5

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

Select an option:> 2

*** ERROR: The contact list is full! ***
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

Select an option:> 3

Enter the cell number for the contact: 6665555
Enter a 10-digit phone number: 6665551111
*** Contact NOT FOUND ***
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

Select an option:> 3

Enter the cell number for the contact: 9051112222

Contact found:
 Maggie R. Greene
    C: 9051112222   H: 9052223333   B: 9053334444
       55 Hightop House, Bolton, A9A 3K3

Do you want to update the name? (y or n): y
Please enter the contact's first name: Maggie
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): R.
Please enter the contact's last name: Greene-Grimes
Do you want to update the address? (y or n): y
Please enter the contact's street number: 55
Please enter the contact's street name: Hightop House
Do you want to enter an apartment number? (y or n): y
Please enter the contact's apartment number: 201
Please enter the contact's postal code: A9A 3K3
Please enter the contact's city: Bolton
Do you want to update the numbers? (y or n): y
Please enter the contact's cell phone number: 905
Enter a 10-digit phone number: 9051112222
Do you want to enter a home phone number? (y or n): n
Do you want to enter a business phone number? (y or n): n
--- Contact Updated! ---
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

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Maggie R. Greene-Grimes
    C: 9051112222   H:              B:
       55 Hightop House, Apt# 201, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should B. Gone
    C: 1112223333   H: 9991112222   B:
       99 No Name Rd., Apt# 11, Nowhere City, A1A J9J
+-----------------------------------------------------------------------------+
Total contacts: 5

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

Enter the cell number for the contact: 9051112222

Contact found:
 Maggie R. Greene-Grimes
    C: 9051112222   H:              B:
       55 Hightop House, Apt# 201, Bolton, A9A 3K3

CONFIRM: Delete this contact? (y or n): n
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

Enter the cell number for the contact: 9051112222

Contact found:
 Maggie R. Greene-Grimes
    C: 9051112222   H:              B:
       55 Hightop House, Apt# 201, Bolton, A9A 3K3

CONFIRM: Delete this contact? (y or n): y
--- Contact deleted! ---
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

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should B. Gone
    C: 1112223333   H: 9991112222   B:
       99 No Name Rd., Apt# 11, Nowhere City, A1A J9J
+-----------------------------------------------------------------------------+
Total contacts: 4

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

Select an option:> 2

Please enter the contact's first name: Where
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Do
Please enter the contact's last name: I Belong
Please enter the contact's street number: 22
Please enter the contact's street name: Somewhere Lane
Do you want to enter an apartment number? (y or n): n
Please enter the contact's postal code: A1A J9J
Please enter the contact's city: Unknown
Please enter the contact's cell phone number: 8883337777
Do you want to enter a home phone number? (y or n): n
Do you want to enter a business phone number? (y or n): y
Please enter the contact's business phone number: 7771115555
--- New contact added! ---
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

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Where Do I Belong
    C: 8883337777   H:              B: 7771115555
       22 Somewhere Lane, Unknown, A1A J9J
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
 I Should B. Gone
    C: 1112223333   H: 9991112222   B:
       99 No Name Rd., Apt# 11, Nowhere City, A1A J9J
+-----------------------------------------------------------------------------+
Total contacts: 5

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

Select an option:> 5

Enter the cell number for the contact: 9052223333

 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3

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

*/