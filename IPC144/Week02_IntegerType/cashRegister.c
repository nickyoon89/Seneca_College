/*
Name:      Jjihyun Yoon
Student#:  124558172
Section:   CPD
*/

// Start your code below:

#include <stdio.h>

int main(void) {
	float amount;
	printf("Please enter the amount to be paid: $");
	scanf("%f", &amount);
	int loonie = (int)amount;
	amount -= loonie;
	printf("Loonies Required: %d, balance Owing $%.2f\n", loonie, amount);
	int quater = amount / 0.25;
	amount -= quater*0.25;
	printf("Quaters Required: %d, balance Owing $%.2f\n", quater, amount);
	return 0;
}
