#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char		*rightShift(char *bin, int k)
{
	int		i;
	char	hold = 0;

	for (i = 5; i >= k; --i)
		bin[i] = bin[i - k];
	++i;
	hold = bin[0];
	while(--i >= 0)
		bin[i] = hold;
	return (bin);
}

char		*leftShift(char *bin, int k)
{
	int		i;

	for (i = 0; i < 6 - k; ++i)
		bin[i] = bin[i + k];
	--i;
	while(bin[++i])
		bin[i] = '0';
	return (bin);
}

int			toInt(char *bits)
{
	int		holder = 0;

	holder = (((holder | (bits[0] - '0')) << 5) | \
			((holder | (bits[1] - '0')) << 4) | \
			((holder | (bits[2] - '0')) << 3) | \
			((holder | (bits[3] - '0')) << 2) | \
			((holder | (bits[4] - '0')) << 1) | \
			((holder | (bits[5] - '0'))));
	if (bits[0] - '0' == 1)
		holder = holder | 0xFFFFFFC0;
	return (holder);
}
