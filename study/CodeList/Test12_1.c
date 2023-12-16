#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int get_info(void);
void show_info();
void menu();
void mode1(char *ch1, char *ch2);

static int mode;
static double distance;
static double oil;
int main(void)
{
	int flag;
	menu();
	while (scanf("%d", &mode))
	{
		flag = get_info();
		if (flag == 0)
			continue;
		if (flag == 3)
			break;
		show_info();
		puts("Please input the mode:");
	}


	return 0;
}
void show_info()
{
	switch (mode)
	{
	case 1:
		printf("%.2f mile and %.2f gallon fuel consumption is: %f(mi/g)\n", distance, oil, distance / oil);
		break;
	case 2:
		printf("%.2f litre and %.2f kilometre fuel consumption is: %f(L/km)\n", oil, distance, oil / distance);
		break;
	default:
		break;
	}
}

int get_info(void)
{
	switch (mode)
	{
	case 1:
		mode1("mile", "gallon");
		return 1;
	case 2:
		mode1("kilometre", "litre");
		return 2;
	case 3:
		return 3;
	default:
		puts("Please input number in (1,2,3)");
		return 0;
	}

}
void mode1(char *ch1, char *ch2)
{
	printf("Please input the oil(%s) and distance(%s):", ch1, ch2);
	while (scanf("%lf %lf", &oil, &distance) != 2)
	{
		puts("Error syntax, try again:");
		while (getchar() != '\n')
			continue;
	}
}

void menu()
{
	puts("Please input the mode(q to quit):");
	printf("1.(mile/gallon)      2.(litre/kilometre)\n");
	printf("3.exit\n");
}