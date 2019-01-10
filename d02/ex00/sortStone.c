#include "header.h"

// itera por grupos sacando el addres inicial y el addres inicial y la llave va a ser su size, luego

// size is the actual number, we are looking for a different one
/*struct	s_stone		*next_stone(struct s_stone *list, int size)
{
	struct	s_stone		*iter = list;
	struct	s_stone		

}*/


struct	s_table		*new_id(int id, struct s_stone *start, struct s_ston *end)
{
	struct s_table		*holder = malloc(sizeof(struct s_table));

	holder->id = id;
	holder->start = start;
	holder->end = end;
	return (holder);
}

void	add_id(struct s_table *new, struct s_table **table)
{
	struct s_table		*iter = NULL;

	if (!(table))
		*table = new;
	else
	{
		for (iter = *table; iter->next; iter = iter->next)
			;
		iter->next = new;
	}
}

void	swap_id_tables(struct s_table *target, struct s_table *source)
{
	struct s_stone	temp_start = source->start;
	struct s_stone	temp_end = source->end;
	int				temp_id = source->id;
	
	source->id = target->id;
	source->start = target->start;
	source->end = target->end;

	target->id = temp_id;
	target->start = temp_start;
	target->end = temp_end;
}

struct	s_stone		*get_group(struct s_table **id_list, struct s_stone **list)
{
	struct s_stone		*iter = list;
	struct s_stone		*start_group = NULL;
	struct s_stone		*end_group = NULL;
	int					holder_id = 0;

	if (iter)
	{
		holder_id = 0;
		start_group = iter;
	}
	while (iter)
	{
		if (iter->size != holder_id)
		{
			add_id(new_id(holder_id, start_group, end_group), id_list);
			return (iter); // another group incoming
		}
		end_group = iter;
		iter = iter->next;
	}
	return (NULL);
}

struct	s_table		

// next group and then keep iterating

void	sortStones(struct s_stone **stone)
{
	struct s_stone		*iter = *stone;
	struct s_table		*id_list = NULL;

	while(get_group(&id_list, stone) != NULL)
		;
	while()


}


/*
void	sortStones(struct s_stone **stone)
{
	struct	s_stone		*first_group = NULL;
	struct	s_stone		*second_group = NULL;
	struct	s_stone		*iter = *stone;
	int					id_first_group = 0;
	int					id_second_group = 0;

	if (iter)
	{
		id_first_group = iter->size;
		first_group = iter;
	}
	while (iter && iter->next)
	{
		if ()
//		id_first_group = iter->size;
		
		if (id_first_group != iter->next->size)
			
	}
	
}
*/
