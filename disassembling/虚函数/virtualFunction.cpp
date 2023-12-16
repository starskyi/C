#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
class People
{
public:
	virtual void say()
	{
		std::cout << "people" << std::endl;
	}
};

class Student : public People
{
public:
	virtual void say()
	{
		std::cout << "student" << std :: endl;
	}
	
};

int main(void)
{
	int a = 4;
	People p;
	Student s;
	People *p1 = &s;
	printf("%d %d\n", sizeof(p), sizeof(s));
	p1->say(); 
	
	
	//system("pause");
	return 0;
}