#include <stdio.h>
#define SIZE 4

struct Employ {
	int ID;
	int age;
	double salary;
};

int main(void) {
	struct Employ emp[SIZE];						        //make Employ structured variable and initialize;
	int option = 1;											//option variable
	int nEmp = 0;											//counting how many employee we have so far
	int i;
	int searchedI;
	int check;												//to check each variable is valid
	int sID;												//searching ID
	printf("---=== EMPLOYEE DATA ===---\n\n");
	while (option != 0) {
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");
		switch (option)
		{
		case 1:												//print employee information
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < nEmp; i++) {
				printf("%6d%9d%11.2lf\n", emp[i].ID, emp[i].age, emp[i].salary);
			}
			printf("\n");
			break;
		case 2:												//add employee
			printf("Adding Employee\n");
			printf("===============\n");
			if (nEmp == SIZE) {								//check if we already got maximum employee
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			else {											//otherwise go on adding
				check = 1;
				while (check) {
					printf("Enter Employee ID: ");
					scanf("%d", &emp[nEmp].ID);
					printf("Enter Employee Age: ");
					scanf("%d", &emp[nEmp].age);
					printf("Enter Employee Salary: ");
					scanf("%lf", &emp[nEmp].salary);
					if (emp[nEmp].ID < 0 || emp[nEmp].age < 0 || emp[nEmp].salary < 0) printf("\nAll number should be positive\n\n");	//check if everything is positive number
					else check = 0;
				}
				printf("\n");
				nEmp++;
			}
			break;
		case 3:												//update employee
			printf("Update Employee Salary\n");
			printf("======================\n");
			if (nEmp == 0) {								//in case there is no employee yet
				printf("\nNo employee to update\n\n");
				break;
			}
			do
			{
				check = 1;
				printf("Enter Employee ID: ");
				scanf("%d", &sID);
				for (i = 0; i < nEmp; i++)
				{
					if (emp[i].ID == sID) break;
					else if (i == nEmp - 1) printf("\nID not found\n\n");
				}
				if (i != nEmp) {
					printf("The current salary is %.2f\n", emp[i].salary);
					printf("Enter Employee New Salary: ");
					scanf("%lf", &emp[i].salary);
					check = 0;
					printf("\n");
				}
			} while (check);
			break;
		case 4:												//remove employee
			printf("Remove Employee\n");
			printf("===============\n");
			if (nEmp == 0) {								//in case there is no employee yet
				printf("\nNo employee to remove\n\n");
				break;
			}
			do
			{
				check = 1;
				printf("Enter Employee ID: ");
				scanf("%d", &sID);
				for (i = 0; i < nEmp; i++)
				{
					if (emp[i].ID == sID) break;
					else if (i == nEmp - 1) printf("\nID not found\n\n");
				}
				if (i != nEmp) {
					check = 0;
					searchedI = i;
					printf("Employee %d will be removed\n\n", emp[searchedI].ID);
					for (i = searchedI; i < nEmp; i++)
					{
						if (i != nEmp - 1) emp[i] = emp[i + 1];
						else emp[i].ID = 0;
					}
					nEmp -= 1;
				}
			} while (check);
			break;
		case 0:												//exit
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		default:											//not valid option input
			printf("ERROR: Incorrect Option: Try Again\n\n");
			break;
		}
		//if (option != 0) option = -1;
	}
	return 1;
}
