#include <stdio.h>
#include <time.h>
#define TIME 1000

int rand1();
void srand1();
void count();
void show();

static unsigned long int next = 1;
static int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0, num10 = 0;
int main(void)
{
	int num;
	srand1((unsigned)time(NULL));
	for (int i = 0; i < TIME; i++)
	{
		num = rand1() % 10 + 1;
		count(num);
	}
	show();
	return 0;
}
void show()
{
	printf("num1 count:%d\nnum2 count:%d\nnum3 count:%d\nnum4 count:%d\nnum5 count:%d\n",
		num1, num2, num3, num4, num5);
	printf("num6 count:%d\nnum7 count:%d\nnum8 count:%d\nnum9 count:%d\nnum10 count:%d\n",
		num6, num7, num8, num9, num10);
}
void count(int num)
{
	switch (num)
	{
	case 1:
		num1++;
		break;
	case 2:
		num2++;
		break;
	case 3:
		num3++;
		break;
	case 4:
		num4++;
		break;
	case 5:
		num5++;
		break;
	case 6:
		num6++;
		break;
	case 7:
		num7++;
		break;
	case 8:
		num8++;
		break;
	case 9:
		num9++;
		break;
	case 10:
		num10++;
		break;
	default:
		break;
	}
}

int rand1()
{
	next = next * 3521548313 - 23451;
	return next % 14823458 + 64313;
}
void srand1(unsigned long int seed)
{
	next = seed;
}


