#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char *getAnd(char *a, char *b)
{
	char		*holder = calloc(1, (sizeof(char) * 4) + 1);

	for (int i = 3; i >= 0; --i)
		holder[i] = ((a[i] - '0') & (b[i] - '0')) + '0';
	return (holder);
}

char *getOr(char *a, char *b)
{
	char		*holder = calloc(1, (sizeof(char) * 4) + 1);

	for (int i = 3; i >= 0; --i)
		holder[i] = ((a[i] - '0') | (b[i] - '0')) + '0';
	return (holder);
}

int			toInt(char *bits)
{
	int		holder = 0;

	holder = (((holder | (bits[0] - '0')) << 3) | \
			((holder | (bits[1] - '0')) << 2) | \
			((holder | (bits[2] - '0')) << 1) | \
			((holder | (bits[3] - '0'))));
	return (holder);
}
