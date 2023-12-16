#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#define MAX 100
#define MIN 0
static int min, max;
int get_rand(int n1, int n2);
void guess_num(int n);
void guess_prep(void);
int main(void)
{
	guess_prep();
	return 0;
}

void guess_prep()
{
	int num;
	int eof;
	puts("Please input the random number range(min max)(ctl + z to exit):");
	while (1)
	{
		
		eof = scanf("%d %d", &min, &max);
		if (eof == EOF)
			return;
		if (eof == 0)
		{
			puts("Please input tow number(min max) in integer");
			while (getchar() != '\n')
				continue;
			continue;
		}
		if (min < 0 || max < min)
		{
			puts("min must be bigger than 0 and max must be bigger than min(min > 0 and max > min)");
			continue;
		}
		if (eof == 2)
		{
			num = get_rand(min, max);
			guess_num(num);
			puts("Please input the random number range(min max)(ctl + z to exit):");
		}

	}
}
int get_rand(int n1, int n2)
{
	srand((unsigned)time(0));
	
	return rand() % (n2 + 1 - n1) + n1;
}
void guess_num(int n)
{
	int num;
	int eof;
	printf("Please star guess the number(%d ~ %d)\n", min, max);
	while (1)
	{
		eof = scanf("%d", &num);
		if (eof == EOF)
			return;
		if (eof != 1)
		{
			while (getchar() != '\n')
				continue;
			puts("Please guess in integer");
		}
		if (num == n)
		{
			printf("Congratulations! you guess right ,the guess number is %d\n", n);
			return;
		}
		else
		{
			if (num > n)
				puts("Fialed, your guess is too big, please try again");
			else
				puts("Fialed, your guess is too small, please try again");
		}
		
	}

}