#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

char		*rightShift(char *bin, int k)
{
	
}

char		*leftShift(char *bin, int k)
{

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
