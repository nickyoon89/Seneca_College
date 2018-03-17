#include <stdio.h>
#define SIZE 2

struct Employ {
	int ID;
	int age;
	double salary;
};

int main(void) {
	int option = 1;											//option variable
	int nEmp = 0;											//counting how many employee we have so far
	int i;						
	int check;												//to check if all ID, Age, Salary is positive number
	struct Employ emp[SIZE];								//make Employ structured variable
	printf("---=== EMPLOYEE DATA ===---\n\n");
	while (option != 0) {
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
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
			if (nEmp == 2) {								//check if we already got maximum employee
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