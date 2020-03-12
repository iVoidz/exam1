#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 50

void printer(int s, int arr[s]);
void rollDie(int s, int r, int arr[]);
int promptRolls();
int promptSides();
int main(void)
{
	int crolls[1024] = {0};
	int sides = 0, rolls  = 0;

	sides = promptSides();
	rolls = promptRolls();

	printer(sides,crolls);
	rollDie(sides,rolls,crolls);
	puts("\nThe number of times you rolled a: \n");

	printer(sides,crolls);
	return EXIT_SUCCESS;
}

int promptSides()
{
	int s = 0;
	printf("Enter the number of sides for your die:\n");
	scanf("%d",&s);
	return s;
}

int promptRolls()
{
	int r = 0;
	printf("Enter the number of rolls:\n");
	scanf("%d",&r);
	return r;
}

void rollDie(int s, int r, int arr[])
{
	int i;
	for(i = 0; i < r; i++)
	{
		srand(time(NULL));
		int num = ((rand() % s) + 1);
		printf("%d", num);
		if(num == i)
			arr[i] = arr[i] + 1;
	}
}

void printer(int s, int arr[s])
{
	int i;
	for(i = 0; i < s; i++)
	{
		printf("\n%d = %d", i, &arr[i]);
	}
}
