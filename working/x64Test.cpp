#include <stdio.h>

int fun1(int n1, int n2, int n3, int n4, int n5, int n6)
{
	return n1 + n2 + n3 + n4 + n5 + n6;
}

float fun2(float n1, float n2, float n3, float n4, float n5, float n6)
{
	return n1 + n2 + n3 + n4 + n5 + n6;
}

float fun3(int n1, float n2, int n3, float n4, int n5, float n6)
{
	return n1 + n2 + n3 + n4 + n5 + n6;
}
int main(void)
{
	fun1(1, 2, 3, 4, 5, 6);
	fun2(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f);
	fun3(1, 2.0f, 3, 4.0f, 5, 6.0f);

}