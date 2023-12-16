#include <stdio.h>
#define SIZE 40
#define COUNT 2

struct name {
	char first[SIZE];
	char last[SIZE];
};

struct friend{
	struct name handle;
	char sex[10];
	char job[SIZE];
	int age;
};

int main(void)
{
	struct friend ones[2] = {
		{{"san", "zhang"},
		"male",
		"teacher",
		25
		},
		{{"si", "li"},
		"male",
		"student",
		16
		}
	};

	struct friend* boy;
	boy = &ones[0];
	printf("%p %p \n", boy, boy + 1);
	printf("boy -> handle[0] is %s , ones[0].handle[0] is %s\n", boy->handle.first, ones[0].handle.first);
	printf("boy -> sex is %s , (*boy).job is %s\n", boy->sex, (*boy).job);
	return 0;
}