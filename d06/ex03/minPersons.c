#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int		minPersons(int elements, int minPercentage)
{
	double	i = 0;
	double	min_d = minPercentage / 100.0;
	double	chances = 1;
	double	something = chances - 1;

	for (i = 0; something < min_d; ++i)
	{
		chances *= ((elements - i) / elements);
		something = 1 - chances;
	}
	return (i);
}
