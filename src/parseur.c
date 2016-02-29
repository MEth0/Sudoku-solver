/*
** parseur.c for sudoku in /home/heurta_s/rendu/after_pool/B2/RUSH/sudoki-bi/src
**
** Made by Stanislav HEURTAULT
** Login   <heurta_s@epitech.net>
**
** Started on  Sat Feb 27 09:11:41 2016 Stanislav HEURTAULT
** Last update Sat Feb 27 14:01:52 2016 Morgan SIMON
*/

#include <string.h>
#include <stdio.h>
#include "my.h"

int	check_lines(char map[11][22])
{
  int	i;
  int	nb;

  i = 1;
  nb = 1;
  while (i < 10)
    {
      if (map[i][0] != '|' || map[i][19] != '|')
	return (1);
      while (nb < 19)
	{
	  if (nb % 2 == 0)
	    {
	      if (map[i][nb] != ' ' && (map[i][nb] < '1' || map[i][nb] > '9'))
		return (1);
	    }
	  else
	    if (map[i][nb] != ' ')
	      return (1);
	  nb++;
	}
      nb = 1;
      i++;
    }
  return (0);
}

int	check_first_last_line(char map[11][22])
{
  int	nb;

  nb = 1;
  if (map[0][0] != '|' || map[0][19] != '|')
    return (1);
  while (nb < 19)
    {
      if (map[0][nb] != '-')
	return (1);
      nb++;
    }
  nb = 1;
  if (map[10][0] != '|' || map[10][19] != '|')
    return (1);
  while (nb < 19)
    {
      if (map[10][nb] != '-')
        return (1);
      nb++;
    }
  return (0);
}

int		check_valid_map(char map[11][22])
{
  size_t	len;
  int		i;

  i = 0;
  while (i < 11)
    {
      len = strlen(map[i]);
      if (len != 21)
	return (1);
      i++;
    }
  return (0);
}

int	parseur(char map[11][22])
{
  if (check_valid_map(map) != 0)
    return (1);
  if (check_first_last_line(map) != 0)
    return (2);
  if (check_lines(map) != 0)
    return (3);
  return (0);
}
