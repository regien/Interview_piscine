#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>

#include "header.h"

// itera por grupos sacando el addres inicial y el addres inicial y la llave va a ser su size, luego

struct	s_table		*new_id(int id, struct s_stone *start, struct s_stone *end)
{
	struct s_table		*holder = malloc(sizeof(struct s_table));

	holder->id = id;
	holder->start = start;
	holder->end = end;
	holder->end->next = NULL;
	return (holder);
}

void	add_id(struct s_table *new, struct s_table **table)
{
	struct s_table		*iter = NULL;

	if (!(*table))
		*table = new;
	else
	{
		for (iter = *table; iter && iter->next; iter = iter->next)
			;
		iter->next = new;
	}
}

void	swap_id_tables(struct s_table *target, struct s_table *source)
{
	struct s_stone	*temp_start = source->start;
	struct s_stone	*temp_end = source->end;
	int				temp_id = source->id;
	
	source->id = target->id;
	source->start = target->start;
	source->end = target->end;

	target->id = temp_id;
	target->start = temp_start;
	target->end = temp_end;
}

// problem with single values in a list

struct	s_stone		*get_group(struct s_table **id_list, struct s_stone **list)
{
	struct s_stone		*iter = *list;
	struct s_stone		*start_group = NULL;
	struct s_stone		*end_group = NULL;
	int					holder_id = 0;

	if (iter)
	{
		holder_id = iter->size;
		start_group = iter;
		end_group = iter;
	}
	while (iter)
	{
		if (iter->size != holder_id)
		{
			add_id(new_id(holder_id, start_group, end_group), id_list);
//			holder_id = iter->size;
//			iter = iter->next;
			*list = iter;
			return (*list); // another group incoming
		}
		else if (!(iter->next))
		{
			end_group = iter;
			add_id(new_id(holder_id, start_group, end_group), id_list);
			*list = iter->next;
			return (iter->next);
		}
		end_group = iter;
		iter = iter->next;
	}
	return (NULL);
}

void				sorted_table(struct s_table *id_list, int size_groups)
{
	struct s_table		*first = id_list;
	struct s_table		*second = NULL;
	int					swapped = 0; //false

//	if (id_list && id_list->next)
//		second = id_list->next;

	for(int i = 0 ; i < size_groups - 1; i++)
	{
		first = id_list;
		second = first->next;
		swapped = 0;
//		second = id_list->next;
		for (int j = 0; j < size_groups - i; ++j)
		{

			if (second->id < first->id)
			{
				swap_id_tables(first, second);
				swapped = 1;
			}
			first = first->next;
			second = first->next;
		}
		if (swapped == 0)
			break;
	}
}


struct s_stone	*relinking(struct s_table *tabla, struct s_stone *stones)
{
	struct s_stone		*holder = NULL;
	struct s_table		*iter = tabla;

	if (!(tabla))
		return (NULL);
	holder = tabla->start;
	while(iter && iter->next)
	{
		iter->end->next = iter->next->start;
		iter = iter->next;
	}
	return (holder);
}

/* test function
void	print_s_tables(struct s_table *tables)
{
	struct s_table		*iter = tables;

	while (iter)
	{
		printf("%d\n", iter->id);
		iter = iter->next;
	}
}
*/

void	sortStones(struct s_stone **stone)
{
	struct s_stone		*iter = *stone;
	struct s_table		*id_list = NULL;
	int					size_groups = 0;

	if (!(*stone) || !(stone[0]))
		return ;

	while(get_group(&id_list, &iter) != NULL)
		size_groups++;
	sorted_table(id_list, size_groups);
	*stone = relinking(id_list, *stone);

}
