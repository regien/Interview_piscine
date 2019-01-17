#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void		permutations(struct s_array *head, int current)
{
	struct s_array		*copy;

	if (current == 0)
	{
		arrayPrint(head);
		free(head);
		return ;
	}
	for (int i = 0; i < current; ++i)
	{
		copy = arrayClone(head);
		arrayAppend(copy, current);
		permutations(copy, current);
	}
}

void		printPossibleSlices(int pizzaSize)
{
	struct s_array		*holder = arrayInit();

	permutations(holder, pizzaSize);
}
