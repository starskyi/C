#include <stdio.h>
#include <string.h>

#define SIZE 40
int main(int argc, char *argv[])
{
	char *name = argv[1];
	if (argc > 2)
	{
		puts("Usage:Main.exe print|to");

	}
	else if (strcmp(name, "print") == 0)
	{
		puts("hello world");
	}
	else if (strcmp(name, "to") == 0)
	{
		puts("to play game");
	}
	else
	{
		puts("Usage:Main.exe print|to");

	}
	return 0;
}