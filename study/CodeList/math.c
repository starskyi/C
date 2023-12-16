#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define SPACE ' '

void menu(void);
void calculate(int ch);
void add();
void substract();
void multiply();
void divide();
void print_tip();
int main(void)
{
	int ch;
	
	printf("%d", 0 == 0.0);
	menu();
	printf("\n>>");
	while ((ch = getchar()) != '5')
	{
		
		calculate(ch);
		while (getchar() != '\n')
			continue;
		printf("\n>>");
	}
	
	return 0;
}

void menu(void)
{
	printf("Enter the apeation of your choice:\n");
	printf("\n1.add             2.substract\n");
	printf("\n3.multiply        4.divide\n");
	printf("\n5.quit\n");

}
void print_tip(void)
{
	printf("Please enter  number(enter q end of input):");
}
void calculate(int ch)
{
	switch (ch)
	{
	case '1':
		//加法
		print_tip();
		add();
		break;
	case '2':
		//减法
		print_tip();
		substract();
		break;
	case '3':
		print_tip();
		multiply();
		//乘法
		break;
	case '4':
		print_tip();
		divide();
		//除法
		break;
	case '5':
		//退出    
		exit(1);
		break;
	default:
		break;
	}
}
void add()
{
	double sum = 0;
	double number;
	
	while (scanf("%lf", &number))
	{
		sum += number;
	}
	printf("%.2f\n", sum);
}

void substract(void)
{
	double diff;
	double number = 0;
	int flag = 0;

	while (scanf("%lf", &number))
	{
		if (flag == 0) {
			flag = 1;
			diff = number;
			continue;
		}
		diff -= number;
	}
	printf("%.2f\n", diff);
}

void divide(void)
{
	double quot = 1;
	double number = 0;
	int flag = 0;
	
	while (scanf("%lf", &number))
	{
		if (flag == 0) {
			flag = 1;
			quot = number;
			continue;
		}
		quot /= number;
	}
	printf("%.2f\n", quot);
}

void multiply(void)
{
	double product;
	double number = 0;
	int flag = 0;

	while (scanf("%lf", &number))
	{
		if (flag == 0) {
			flag = 1;
			product = number;
			continue;
		}
		product *= number;
	}
	printf("%.2f\n", product);
}