#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int			toInt(char *a)
{
	int		holder = 0;

	holder = (((holder | (a[0] - '0')) << 5) | \
			((holder | (a[1] - '0')) << 4) | \
			((holder | (a[2] - '0')) << 3) | \
			((holder | (a[3] - '0')) << 2) | \
			((holder | (a[4] - '0')) << 1) | \
			((holder | (a[5] - '0'))));
	return (holder);
}


char		*getSum(char *a, char *b)
{
	char	*result = calloc(1, sizeof(char) * 6);
	int		carry = 0;

	for (int i = 5; i >= 0; i--)
	{
		result[i] = (((a[i] - '0') ^ (b[i] - '0') ^ carry) + '0');
		carry = (((a[i] - '0') & (b[i] - '0')) | ((b[i] - '0') & carry) | \
				((a[i] - '0') & carry));
	}
	return(result);
}
