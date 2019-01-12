#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

struct s_node	*create_node(int value)
{
	struct s_node		*holder = malloc(sizeof(struct s_node));
	holder->value = value;
	holder->right = NULL;
	holder->left = NULL;
	return (holder);
}

struct s_node	*find_middle(int *arr, int start, int end)
{
	if (start > end)
		return (NULL);

	int		mid = (start + end) / 2;
	struct s_node		*holder = create_node(arr[mid]);
	holder->left = find_middle(arr, start, mid - 1);
	holder->right = find_middle(arr, mid + 1, end);
	return (holder);
}

struct s_node *createBST(int *arr, int n)
{
	struct s_node		*holder = NULL;

	if (n <= 0)
		return (NULL);
	holder = find_middle(arr, 0, n - 1);
	return (holder);
}
