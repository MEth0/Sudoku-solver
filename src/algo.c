/*
** alogo.c for sudoku in /home/simon_z/rendu/Rush/sudoki-bi
**
** Made by Morgan SIMON
** Login   <simon_z@epitech.net>
**
** Started on  Sat Feb 27 10:26:09 2016 Morgan SIMON
** Last update Sun Feb 28 13:34:06 2016 Morgan SIMON
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

int	check_block(int w, int map[9][9], int i, int j)
{
  int	ti;
  int	tj;

  ti = 3 * (i / 3);
  tj = 3 * (j / 3);
  i = ti;
  while (i < ti + 3)
    {
      j = tj;
      while (j < tj + 3)
	{
	  if (map[i][j] == w)
	    return (-1);
	  j++;
	}
      i++;
    }
  return (0);
}

int	check_col(int w, int map[9][9], int j)
{
  int	i;

  i = 0;
  while (i < 9)
    {
      if (map[i][j] == w)
	return (-1);
      i++;
    }
  return (0);
}

int	check_line(int w, int map[9][9], int i)
{
  int	j;

  j = 0;
  while (j < 9)
    {
      if (map[i][j] == w)
	return (-1);
      j++;
    }
  return (0);
}

int	calc(int map[9][9], int pos)
{
  int	i;
  int	j;
  int	w;

  if (pos == -1)
    return (0);
  i = pos / 9;
  j = pos % 9;
  if (map[i][j] != 0)
    return (calc(map, pos - 1));
  w = 1;
  while (w <= 9)
    {
      if (check_line(w, map, i) == 0 &&
	  check_col(w, map, j) == 0 &&
	  check_block(w, map, i, j) == 0)
	{
	  map[i][j] = w;
	  if (calc(map, pos - 1) == 0)
	    return (0);
	}
      w++;
    }
  map[i][j] = 0;
  return (-1);
}
