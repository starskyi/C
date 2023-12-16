#include <stdio.h>

int main(void)
{
	const short MAX_NUM = 64;
	int num = 1;
	double curgrains = 0, total = 0;
	
	

	printf("%-8s %-8s %-8s\n", "curnum", "grains", "total");
	while (num <= MAX_NUM)
	{ 
		curgrains = total + 1;
		
		total += curgrains;
		printf("%-8d %-8.2e %-8.2e\n", num, curgrains, total);
		num++;
	}

	return 0;
}