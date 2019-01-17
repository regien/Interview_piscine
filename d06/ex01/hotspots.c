#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"



int selectHotspots(struct s_hotspot **hotspots)
{
	struct s_hotspot		*holder = NULL;
	int						count = 0;

	for (int i = 0; hotspots[i]; ++i)
	{
		if (!holder)
		{
			holder = hotspots[i];
			count++;
		}
		else
		{
			if (abs(holder->pos - hotspots[i]->pos) > \
			(holder->radius >= hotspots[i]->radius ? holder->radius : hotspots[i]->radius))
			{
				holder = hotspots[i];
				count++;
			}
		}
	}
	return (count);
}
