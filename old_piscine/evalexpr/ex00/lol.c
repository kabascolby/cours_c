#include "header.h"

int	fuck_the_police(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (2);
	if (c == '/')
		return (3);
	if (c == '*')
		return (4);
	if (c == '%')
		return (5);
	return (0);
}
