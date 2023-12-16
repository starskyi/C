#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 2048
#define SIZE 40

int copy(FILE* src, FILE* des);
int main(void)
{
	char src_name[SIZE];
	char des_name[SIZE];
	FILE* sp, * dp;
	
	printf("Please input the source file name(input # to quit):\n");
	while (scanf("%s", src_name) && src_name[0] != '#')
	{
		while ((sp = fopen(src_name, "rb")) == NULL)
		{
			printf("Cannot open file:%s\n", src_name);
			puts("Please input other name:");
			scanf("%s", src_name);
		}
		setvbuf(sp, NULL, _IOFBF, BUFSIZE);

		printf("Please input the destination file name:\n");
		scanf("%s", des_name);
		while ((dp = fopen(des_name, "wbx")) == NULL)
		{
			printf("Cannot open file:%s\n", des_name);
			puts("Please input other name:");
			scanf("%s", des_name);
		}
		setvbuf(dp, NULL, _IOFBF, BUFSIZE);

		copy(sp, dp);
		//fflush(dp);
		fclose(dp);
		fclose(sp);
		printf("Please input the source file name(input # to quit):\n");
	}
	
	return 0;
}

int copy(FILE *src, FILE *des)
{
	char data[BUFSIZE];
	int n;
	size_t a;
	size_t bytes = 0;
	while ((n = fread(data, sizeof(char), BUFSIZE, src)) > 0)
	{
		bytes += fwrite(data, sizeof(char), n, des);
	}
	printf("Complete!\n");
	printf("A total of %zd bytes were copied\n", bytes);
	return 1;
}