#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void	heapify(struct s_art **masterpiece, int n)
{

}

void	heapSort(struct s_art **masterpiece, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(masterpiece, n, i);
	}
}
