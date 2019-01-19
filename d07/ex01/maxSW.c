#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"


/*
 *https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
 *
 */

struct s_deque *dequeInit(void)
{
	struct s_deque		*holder = calloc(1, sizeof(struct s_deque));

	holder->first = NULL;
	holder->last = NULL;
	return (holder);
}

struct s_dequeNode		create_node(int value)
{
	struct s_dequeNode	*holder = calloc(1, sizeof(struct s_dequeNode));

	holder->value = value;
	holder->next = NULL;
	holder->prev = NULL;
	return (holder);
}

void pushFront(struct s_deque *deque, int value);
{
	
}
void pushBack(struct s_deque *deque, int value);
int popFront(struct s_deque *deque);
int popBack(struct s_deque *deque);

int			is_empty(struct s_deque *dequeue)
{
	if (!(dequeue->first))
		return (1);
	else
		return (0);
}

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	struct s_max	*greatest = calloc(1, sizeof(struct s_max));
	struct s_deque	*dequeue = dequeInit();
//	int				great = 0;
//	int				position = 0;
	int				i = 0;
	int				e = 0;

	greatest->max = calloc(1, sizeof(int) * ((n - k) + 1));
	greatest->length = ((n - k) + 1);
/*	if (n > 0)
		great = arr[0];
	for (int i = 0; i < (n - k); ++i) {
		max = arr[i]
	}*/

	for (i = 0; i < k; ++i) {
		while((is_empty(dequeue) == 0 && arr[i] >= arr[dequeue->last->value]))
			popBack(dequeue);
		pushBack(dequeue ,i);
	}

	for (; i < n; ++i, ++e)
	{
		greatest->max[e] = arr[dequeue->first->value];
		
		while(is_empty(dequeue) == 0 && dequeue->first->value <= i - k)
			popFront(dequeue);

		while(is_empty(dequeue) == 0 && arr[i] >= arr[dequeue->last->value])
			popBack(dequeue);

		pushBack(dequeue, i);
	}
	return (greatest);
}


