#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char *getXor(char *a, char *b)
{
	char	*holder = calloc(1, sizeof(char) * 6 + 1);

	for (int i = 0; i < 6; i++)
		holder[i] = ((a[i] - '0') ^ (b[i] - '0') + '0');
	return (holder);
}

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
