#include <stdio.h>
#include <string.h>
int main(void)
{
	
	char file[40];
	//fgets(file1, 40, stdin);
	gets_s(file, 40);
	printf("%s %d %d\n", file, strlen(file), sizeof(file));

}