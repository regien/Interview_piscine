#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void sinkIsland(int **map, int row, int col)
{
	if (row > 0 || col > 0 || map[row] == NULL || map[row][col] <= '0')
		return ;
	map[row][col] = 0;
	sinkIsland(map, row - 1, col);
	sinkIsland(map, row + 1, col);
	sinkIsland(map, row, col + 1);
	sinkIsland(map, row, col - 1);
}