#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

struct	s_node			*ancestro = NULL;

/*
** flag 0 nothing, 1 s1 found, 2 s2 found, 3 todo, then set 3
*/
int			traver_sing(struct s_node *root, char *s1, char *s2, int flag)
{
	int				new_flag = flag;

	if (!root)
		return (flag);
	for (int i = 0; root->children && root->children[i] != NULL; ++i)
		new_flag |= traver_sing(root->children[i], s1, s2, flag);
	new_flag |= ((strcmp(s1, root->name) == 0 ? 1 : 0) | \
			(strcmp(s2, root->name) == 0 ? 2 : 0) | flag);
//	printf("new_flag = %d ", new_flag);
//	printf("root->name = %s\n", root->name);
	if (new_flag == 3 && ancestro == NULL)
		ancestro = root;
	return (new_flag | flag);
	
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	if (!root)
		return (ancestro);
	traver_sing(root, firstSpecies, secondSpecies, 0);
//	printf("%p\n", ancestro);
	return(ancestro);
}
