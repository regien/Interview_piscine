#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"


int isFilled(unsigned int parkingRow)
{
	int		holder = ((((parkingRow >> 1) ^ parkingRow) << 1) & parkingRow);
	
	holder = (holder >> 16) | holder;
	holder = (holder >> 8) | holder;
	holder = (holder >> 4) | holder;
	return (0x01 >> (holder & 0xf));
}
