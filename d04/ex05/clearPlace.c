#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"


unsigned int clearPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow ^ (((parkingRow >> pos) & 1) << pos));
}