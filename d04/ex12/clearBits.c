#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

unsigned int clearBits(unsigned int parkingRow, int n)
{
	int		holder = 0;

	holder = ~holder;
	holder = (holder << n);
	return (parkingRow & holder);
}
