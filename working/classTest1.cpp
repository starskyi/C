#include <stdio.h>

class Base
{
public:
	Base()
	{
		printf("Base::Base()\n");
	}
};
class Child : Base
{
public:
	Child()
	{
		printf("Child::Child()\n");
	}
};

int main(void)
{
	Child child;
}