#include <stdio.h>
#define NUMS 3

int main(void) {

	int totalLow = 0;
	int totalHigh = 0;
	int inputLow;
	int inputHigh;
	int flag;
	int i;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++)
	{
		flag = 1;
		inputHigh = 0;
		inputLow = 0;
		while (flag)
		{
			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &inputHigh);
			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &inputLow);
			printf("\n");
			if (inputHigh<41 && inputLow>-41 && inputHigh > inputLow) {
				flag = 0;
				totalHigh += inputHigh;
				totalLow += inputLow;
			}
			else {
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
			}
		}
	}
	printf("The average (mean) temperature was: %.2f\n",(totalHigh+totalLow)/(2.0*NUMS));
	return 0;
}
