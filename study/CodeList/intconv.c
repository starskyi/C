#include <stdio.h>
#define PAGES 15
#define WORDS 65471
int main(void)   //ÀàÐÍ×ª»»
{
	unsigned short unsinum= WORDS;
	short num = PAGES;
	short mnum = -PAGES;
	printf("Number as short and unsigned short %hd %hu\n", WORDS, WORDS);
	printf("Number as -short and unsigned short %hd %hu\n", -WORDS, WORDS);
	printf("Number as short and unsigned short %hd %hu\n", num, num);
	printf("Number as short and unsigned short %hd %hu\n", mnum, mnum);
	printf("%hu %hu\n", unsinum, -unsinum);
	printf("%hu %hd %c %d\n", unsinum, -unsinum, -unsinum, unsinum);
	


	return 0;
}