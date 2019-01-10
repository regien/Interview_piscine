#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdio.h>

struct					s_stone {
	int					size;
	struct s_stone		*next;
};

#endif
