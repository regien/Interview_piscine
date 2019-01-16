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

int		substract(int x, int y)
{
	if (y)
		return (substract(x ^ y, (~x & y) << 1));
	else
		return (x);
}

// log n complexity
int occupiedPlaces(unsigned int parkingRow)
{
	int		holder = 0;

	while (parkingRow)
	{
		parkingRow &= (substract(parkingRow, 1));
		holder = adding(holder, 1);
	}
	return (holder);
}
