#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"


void	swap(struct s_art *s1, struct s_art *s2)
{
	char			*holder = s1->name;
	int				price = s1->price;

	s1->name = s2->name;
	s1->price = s2->price;
	s2->name = holder;
	s2->price = price;
}

void	heapify(struct s_art **arr, int n, int i)
{
	int		largest = i;
	int		left = 2 * i + 1;
	int		right = 2 * i + 2;

	// check case-sensitive - check if there are equal and then check the next
	// char
	if (left < n && (unsigned char)arr[left]->name[0] > \
			(unsigned char)arr[largest]->name[0])
		largest = left;
/*	else if (left < n && (unsigned char)arr[left]->name[0] == \
			(unsigned char)arr[largest]->name[0])
	{
		for (int i = 1;  arr[left]->name[i] && arr[largest]->name[i] \
				&& (unsigned char)arr[left]->name[i] == \
				(unsigned char)arr[largest]->name[i]; ++i)
			if ((unsigned char)arr[left]->name[i] > \
					(unsigned char)arr[largest]->name[i])
			{
				largest = left;
//				break ;
			}
	}*/

	if (right < n && (unsigned char)arr[right]->name[0] > \
			(unsigned char)arr[largest]->name[0])
		largest = right;
/*	else if (right < n && (unsigned char)arr[right]->name[0] == \
			(unsigned char)arr[largest]->name[0])
	{
		for (int i = 1;  arr[right]->name[i] && arr[largest]->name[i]\
				&& (unsigned char)arr[left]->name[i] == \
				(unsigned char)arr[largest]->name[i]; ++i)
			if ((unsigned char)arr[right]->name[i] > \
					(unsigned char)arr[largest]->name[i])
			{
				largest = right;
//				break ;
			}
	}*/

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n , largest);
	}
}

void	heapSort(struct s_art **masterpiece, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(masterpiece, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(masterpiece[0], masterpiece[i]);
		heapify(masterpiece, i, 0);
	}
}

