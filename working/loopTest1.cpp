#include <stdio.h>

void forTest()
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", i);
	}
}

void whileTest()
{
	int i = 0;
	while (i < 5)
	{
		printf("%d\n", i);
		i++;
	}
}

void doWhileTest()
{
	int i = 0;
	do {
		printf("%d\n", i);
		i++;
	} while (i < 5);
}

int main(void)
{
	forTest();
	whileTest();
	doWhileTest();
}