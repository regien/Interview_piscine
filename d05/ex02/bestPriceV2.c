#include <stdio.h>  //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

double	permutations(int pizzaSize, double *prices, double *holder)
{
	double		mejor = prices[pizzaSize];

	if (holder[pizzaSize])
		return (holder[pizzaSize]);
	for (int i = 0; i <= pizzaSize / 2; ++i)
	{
		if (((permutations(pizzaSize - i, prices, holder) + permutations(i, prices, holder)) > mejor)
			mejor = holder[pizzaSize - i] + holder[i];
	}
	holder[pizzaSize] = best;
	return (mejor);
}



double bestPrice(int pizzaSize, double *prices)
{
	double	*holder = calloc(pizzaSize, sizeof(double));
	double	result = 0;

	result = permutations(pizzaSize, prices, holder);
	return (mejor);
}