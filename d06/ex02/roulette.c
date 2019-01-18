#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <math.h>

#include "header.h"

/*
** do the same and calculate the steps
** steps = ceil(log2(dollarswanted / initial_money));
*/

double	helper(double initial_money, double target_money, int nb_games)
{
	if (initial_money >= target_money)
		return (1);
	else if (nb_games == 0)
		return (0);
	return (((18.0/37) * helper(initial_money * 2, target_money, nb_games - 1)) + \
			((1.0/37) * helper(initial_money / 2, target_money, nb_games - 1)));
}

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
	return (helper(firstDollarsBet, dollarsWanted, nbGame));
}
