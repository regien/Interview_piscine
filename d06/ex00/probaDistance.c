#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

double probaDistance(int dist, int *locations, int n)
{
	double			holder = 0;
	double			count = 0;
	const double	div = ((n * n) - n);

	if (n == 0)
		return (0);
	for (int i = 0; i < n; ++i)
	{
		for (int e = 0; e < n; ++e)
			if (e == i)
				;
			else
				abs(locations[e] - locations[i]) > dist ? count++ : 0;
	}
	holder = count / div;
	return (holder);
}
