#include <stdio.h>  //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void	permutations(int pizzaSize, double *mejor, double *prices, double sum)
{
	if (pizzaSize == 0)
	{
		if (sum < *mejor)
			*mejor = sum;
		return ;
	}
	
	for (int i = 1; i < pizzaSize; ++i)
		permutations(pizzaSize, mejor, prices, sum + prices[i]);
}

double bestPrice(int pizzaSize, double *prices)
{
	double	mejor = 0;
	
	permutations(pizzaSize, &mejor, prices, 0);
	return (mejor);
}