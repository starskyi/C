#include <stdio.h>
#include <stdbool.h>
/*边框样式*/
#define SOLID 0
#define DOTTED 1
#define DASHED 2

/*三原色*/
#define RED 1
#define GREEN 2
#define BLUE 4

/*混合色*/
#define BLACK 0
#define YELLOW (RED|GREEN)
#define MAGENTA (RED|BLUE)
#define CYAN (GREEN|BLUE)
#define WHITE (RED|GREEN|BLUE)

/*按位用到的符号常量*/
#define OPAQUE 0x1
#define FILL_COLOR 0xE
#define BORDER_COLOR 0x7
#define BORDER_STYLE 0x3

char* colors[] = { "black", "red", "green", "yellow", "blue", "magenta", "cyan", "white" };
char* style[] = {"solid", "dotted", "dashed"};
struct box_props {
	unsigned int opaque : 1;
	unsigned int fill_color : 3;
	unsigned int : 4;
	unsigned int show_border : 1;
	unsigned border_color : 3;
	unsigned border_style : 2;
	unsigned int : 2;
};

union view {
	struct box_props st_view;
	unsigned short us_view;
};

void show_setting(const struct box_props* box);
void show_setting1(unsigned short box);
void itobs(int );


int main(void)
{
	union view box = {{true, RED, false, BLUE, SOLID}};

	printf("Box settings use struct:\n");
	itobs((int)box.us_view);
	show_setting(&box.st_view);

	printf("Box settings use unsigned short:\n");
	itobs((int)box.us_view);
	show_setting1(box.us_view);
	

	box.us_view ^= 1;
	box.us_view ^= 0x100;
	puts("The new value is:");
	itobs((int)box.us_view);
	show_setting1(box.us_view);


	return 0;
}
void show_setting(const struct box_props* box)
{
	printf("%s \n", box->opaque == true ? "opaque" : "transparent");
	printf("%s \n", colors[box->fill_color]);
	printf("%s \n", box->show_border == true ? "shown" : "no shown");
	printf("%s \n", colors[box->border_color]);
	printf("%s \n", style[box->border_style]);


}


void show_setting1(unsigned short box)
{
	printf("%s\n", (box & OPAQUE) == 1 ? "opaque" : "transparent");
	printf("%s\n", colors[(box & FILL_COLOR) >> 1]);
	printf("%s \n", box >> 8 & 1 == true? "shown":"no shown");
	printf("%s \n", colors[box >> 9 & BORDER_COLOR]);
	printf("%s \n", style[box >> 12 & BORDER_STYLE]);
}

void itobs(int box)
{
	for (int i = 31; i >= 0; i--)
	{
		printf("%d", (box >> i) & 1);
		if ((i) % 4 == 0)
			printf(" ");
	}
	printf("\n");
}
