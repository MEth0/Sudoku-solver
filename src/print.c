/*
** print.c for sudoku in /home/simon_z/rendu/Rush/sudoki-bi
**
** Made by Morgan SIMON
** Login   <simon_z@epitech.net>
**
** Started on  Sat Feb 27 13:47:05 2016 Morgan SIMON
** Last update Sat Feb 27 18:04:29 2016 Morgan SIMON
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

void    print_x()
{
  int   i;

  i = 0;
  printf("|------------------|\n");
  while (i < 9)
    {
      printf("| X X X X X X X X X|\n");
      i++;
    }
  printf("|------------------|\n");
}

void    print_map(int map[9][9])
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  printf("|------------------|\n");
  while (i < 9)
    {
      printf("|");
      while (nb < 9)
        {
          printf(" %d", map[i][nb]);
          nb++;
        }
      nb = 0;
      i++;
      printf("|\n");
    }
  printf("|------------------|\n");
}

int     what_do_i_print(int map[9][9])
{
  if (check_double(map) != 0)
    print_x();
  else
    {
      if (calc(map, 80) == -1)
        return (1);
      print_map(map);
    }
  return (0);
}
