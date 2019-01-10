#include "header.h"

// helper and the main function print a newline

void		helper(struct s_node *list)
{
	if (!(list->next))
		printf("%s", list->word);
	else
	{
		helper(list->next);
		printf(" %s", list->word);
	}
}

void		printReverse(struct s_node *list)
{
	helper(list);
	printf("\n");
}
