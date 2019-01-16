#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int		substract(int x, int y)
{
	if (y)
		return (substract(x ^ y, (~x & y) << 1));
	else
		return (x);
}

int leftmostCar(unsigned int parkingRow)
{
	return (substract(fls(parkingRow), 1));
}
