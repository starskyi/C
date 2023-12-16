#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int a_count = 0, e_count = 0, i_count = 0, o_count = 0, u_count = 0;
	char ch;

	printf("Please input letters:");

	while ((ch = toupper(getchar())) != '#')
	{
		switch(ch)
		{
		case 'A': a_count++;
			break;
		case 'E': e_count++;
			break;
		case 'I': i_count++;
			break;
		case 'O': o_count++;
			break;
		case 'U': u_count++;
			break;
		default:
			break;
		}
	}
	printf("There are %d 'A' letter , %d 'E' letter, %d 'I' letter,%d 'O' letter, %d 'U' letter in total\n",
		a_count, e_count, i_count, o_count, u_count);

	return 0;
}