#include <stdio.h>
#include <stdlib.h>

char * get_str(char* chs[], int n);
int main(void)
{
	char* chs[2];
	printf("%zd\n", sizeof(chs[0]));
	char *p = get_str(chs, 2);
	printf("%zd %p %s\n", sizeof(chs[0]), chs[0], chs[0]);
	free(p);
	printf("%zd %p %s\n", sizeof(chs[0]), chs[0], chs[0]);
	return 0;
}

char * get_str(char* chs[], int n)
{
	*chs = (char*)malloc(40 * sizeof(char));
	printf("%p\n", *chs);
	char ch;
	int i = 0;
	while ((ch = getchar()) != '\n')
	{
		*((*chs) + i) = ch;
		i++;

	}
	*((*chs) + i) = '\0';
	printf("%s\n", *chs);
	return *chs;
}