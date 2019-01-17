#include <stdio.h>  //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

// this is literally from geeks for geeks permutatione example
void	swap(char *str, int i, int j)
{
	char	tmp = str[i];

	str[i] = str[j];
	str[j] = tmp;
}

void	permutation(char *str, int start)
{
	if (!str[start])
		printf("%s\n", str);
	for (int i = start; str[i]; ++i)
	{
		swap(str, start, i);
		permutation(str, start + 1);
		swap(str, start, i);
	}
}

void	printPermutations(char *str)
{
	permutation(str, 0);
}