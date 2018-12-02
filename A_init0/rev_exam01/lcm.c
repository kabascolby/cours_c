#include <stdio.h>

int main()
{
	int a, b, max, step, lcm;

	a = 3;
	b = 4;
	lcm = 0;

	if (a > b)
		max = step = a;
	else
		max = step = b;

	while (1)
	{
		if (max % a == 0 && max % b == 0)
		{
			lcm = max;
			break;
		}

		max += step;
	}

	printf("LCM is %d", lcm);
	return 0;
}

unsigned int  hcf(unsigned int a, unsigned int b)
{
	if(b == 0)
		return(a);
	return(hcf(b, (a%b)));
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
	return((a * b) / hcf(a,b));
}