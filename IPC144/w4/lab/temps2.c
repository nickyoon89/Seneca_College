#include <stdio.h>
int main(void) {
	int inputNo;
	int high[10];
	int low[10];
	int i;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &inputNo);
	while (inputNo<3||inputNo>10) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &inputNo);
	}
	printf("\n");
	for (i = 0; i < inputNo; i++){
		printf("Day %d - High: ",i+1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ",i+1);
		scanf("%d", &low[i]);
	}
	printf("\nDay  Hi  Low\n");
	for (i = 0; i < inputNo; i++) {
		printf("%d    %d    %d\n", i+1,high[i],low[i]);
	}
	return 0;
}