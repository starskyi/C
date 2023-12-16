#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define SIZE 40
struct name {
	char first[SIZE];
	char last[SIZE];
	int letters;
};

void getinfo(struct name* one1);
void makeinfo(struct name* one1);
void showinfo(const struct name* one1);

int main(void)
{
	struct name one1;
	
	getinfo(&one1);
	makeinfo(&one1);
	showinfo(&one1);

	return 0;
}

void showinfo(const struct name* one1)
{
	printf("you have %d letters of name in total", one1->letters);
}
void makeinfo(struct name* one1)
{
	one1->letters = strlen(one1->first) + strlen(one1->last);
}

void getinfo(struct name* one1)
{
	puts("Please input the first name:");
	scanf("%s", one1->first);
	puts("Please input the last name:");
	scanf("%s", one1->last);
}