/*
** pre_algo.c for sudoku in /home/heurta_s/CLONES/sudoki-bi/src
**
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
**
** Started on  Sat Feb 27 11:58:51 2016 Stanislav HEURTAULT
** Last update Sat Feb 27 14:03:56 2016 Morgan SIMON
*/

#include "my.h"

int	check_line_map(int map[9][9], int i, int nb)
{
  int	keep;

  keep = nb;
  while (nb < 9)
    {
      if (map[i][nb] != 0 && nb != keep)
	{
          if (map[i][keep] == map[i][nb])
            return (1);
        }
      nb++;
    }
  return (0);
}

int	check_column_map(int map[9][9], int i, int nb)
{
  int	keep;

  keep = i;
  while (i < 9)
    {
      if (map[i][nb] != 0 && i != keep)
        {
          if (map[keep][nb] == map[i][nb])
            return (1);
        }
      i++;
    }
  return (0);
}

int	check_da_block(int map[9][9], int i, int j)
{
  int	ti;
  int	tj;
  int	keepi;
  int	keepj;

  ti = 3 * (i / 3);
  tj = 3 * (j /3);
  keepi= i;
  keepj= j;
  i = ti;
  while (i < ti + 3)
    {
      j= tj;
      while (j < tj + 3)
	{
          if (map[keepi][keepj] != 0 && map[i][j] == map[keepi][keepj]
	      && i != keepi)
	    return (1);
          j++;
        }
      i++;
    }
  return (0);
}

int	check_for_blocks(int map[9][9])
{
  int	nb;
  int	i;
  int	j;

  nb = 0;
  while (nb < (9 * 9))
    {
      i = nb / 9;
      j = nb % 9;
      if (check_da_block(map, i, j) != 0)
        return (1);
      nb++;
    }
  return (0);
}

int	check_double(int map[9][9])
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (i < 9)
    {
      while (nb < 9)
        {
          if (check_line_map(map, i, nb) != 0)
            return (1);
          if (check_column_map(map, i, nb) != 0)
            return (1);
          nb++;
        }
      nb = 0;
      i++;
    }
  if (check_for_blocks(map) != 0)
    return (1);
  return (0);
}
