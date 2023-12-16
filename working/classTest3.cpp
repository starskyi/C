#include <stdio.h>

class Student
{
private:
	int a = 1;
	int b = 2;
public:
	void set(int a, int b)
	{
		this->a = a;
		this->b = b;
		printf("%d %d\n", this->a, this->b);
	}
};

int main(void)
{
	Student s1;
	s1.set(4, 5);

	return 0;
}