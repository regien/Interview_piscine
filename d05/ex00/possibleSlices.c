#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void		permutations(int *arr, int i, int j)
{
	int		holder = arr[i];

	arr[i] = arr[j];
	arr[j] = holder;
}

void		permutations(struct s_array *base, int currentindex)
{
	
}

void		printPossibleSlices(int pizzaSize)
{
	struct s_array		*holder = arrayInit();

	for (int i = 1; pizzaSize > 0; ++i, pizzaSize--)
	{
		arrayAppend(holder, i);
		if (holder.sum == 4)
			permutations(holder, 0)
	}
		

	
	free(holder);
}
