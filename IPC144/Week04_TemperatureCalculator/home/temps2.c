#include <stdio.h>
int main(void) {
	int inputNo;
	int inputAvgNo = 1;
	int high[10];
	int low[10];
	int theHighest;
	int theHighestD;
	int theLowest;
	int theLowestD;
	float avgTemp;
	int i;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &inputNo);
	while (inputNo < 3 || inputNo>10) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &inputNo);
	}
	printf("\n");
	for (i = 0; i < inputNo; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
		if (i == 0 || low[i] < theLowest) {
			theLowest = low[i];
			theLowestD = i + 1;
		}
		if (i == 0 || high[i] > theHighest) {
			theHighest = high[i];
			theHighestD = i + 1;
		}
	}
	printf("\nDay  Hi  Low\n");
	for (i = 0; i < inputNo; i++) {
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);
	}
	printf("\nThe highest temperature was %d, on day %d", theHighest, theHighestD);
	printf("\nThe lowest temperature was %d, on day %d\n\n", theLowest, theLowestD);
	while (inputAvgNo > 0) {
		printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", inputNo);
		scanf("%d", &inputAvgNo);
		printf("\n");
		while (inputAvgNo<1 || inputAvgNo>inputNo) {
			if (inputAvgNo < 0) {
				printf("Goodbye!\n");
				break;
			}
			else {
				printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", inputNo);
				scanf("%d", &inputAvgNo);
				printf("\n");
			}
		}
		if (inputAvgNo > 0) {
			avgTemp = 0;
			for (i = 0; i < inputAvgNo; i++)
			{
				avgTemp += high[i];
				avgTemp += low[i];
			}
			avgTemp /= (inputAvgNo * 2);
			printf("The average temperature up to day %d is: %.2f\n\n",inputAvgNo,avgTemp);
		}
	}
	return 0;
}