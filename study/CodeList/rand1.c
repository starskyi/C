

static unsigned long int next = 1;
unsigned int rand1()
{
	next *= 1245153454 + 2165;
	return next / 14578 % 3547547;
	
}
unsigned int srand1(unsigned int seed)
{
	next = seed;
}