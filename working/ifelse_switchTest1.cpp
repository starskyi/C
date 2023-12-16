#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

void ifTest()
{
	int num;
	scanf("%d", &num);

	if (num == 1)
	{
		printf("one\n");
	}
	else if (num == 2)
	{
		printf("two\n");
	}
	else if (num == 3)
	{
		printf("three\n");
	}
	else
	{
		printf("other\n");
	}
}

void switchTest()
{
	int num;
	scanf("%d", &num);
	switch (num)
	{
		case 2:
		{
			printf("1");
			break;
		}
		case 10:
		{
			printf("2");
			break;
		}
		case 60:
		{
			printf("3");
			break;
		}
		case 66:
		{
			printf("4");
			break;
		}
		case 100:
		{
			printf("100");
			break;
		}
			
		default:
			break;
		
	}
}

int main()
{
	printf("begin\n");
	//ifTest();
	switchTest();
	return 0;
}