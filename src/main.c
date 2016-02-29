/*
** main.c for sudoku in /home/simon_z/rendu/Rush/sudoki-bi
**
** Made by Morgan SIMON
** Login   <simon_z@epitech.net>
**
** Started on  Fri Feb 26 19:36:00 2016 Morgan SIMON
** Last update Sat Feb 27 21:48:06 2016 Morgan SIMON
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

int		main()
{
  int		map[9][9];
  char		tab[11][22];
  int		nb[2];

  nb[0] = 0;
  while (nb[0] >= 0)
    {
      if ((nb[1] = get_map(tab)) == 1)
	nb[0] = -1;
      if (nb[0] >= 0)
	{
	  if (nb[0] > 0)
	    printf("####################\n");
	  if (parseur(tab) != 0 || nb[1] == 2)
	    {
	      printf("MAP ERROR\n\n");
	      return (1);
	    }
	  get_in_map(tab, map);
	  if (what_do_i_print(map) != 0)
	    return (1);
          nb[0]++;
	}
    }
  return (0);
}
