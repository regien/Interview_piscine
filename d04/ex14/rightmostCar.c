#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int		adding(int x, int y)
{
	if (y)
		return (adding( x ^ y, (x & y) << 1));
	else
		return (x);
}

int		helper(unsigned int parkingRow, int times)
{
	if (times == 32)
		return (-1);
	if ((parkingRow & 1) == 1)
		return (times);
	return (helper(parkingRow >> 1, adding(times, 1)));
}

int rightmostCar(unsigned int parkingRow)
{
	return (helper(parkingRow, 0));
}
