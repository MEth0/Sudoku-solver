/*
** init.c for sudoku in /home/simon_z/rendu/Rush/sudoki-bi
**
** Made by Morgan SIMON
** Login   <simon_z@epitech.net>
**
** Started on  Sat Feb 27 13:48:17 2016 Morgan SIMON
** Last update Sun Feb 28 11:27:27 2016 Morgan SIMON
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

int     get_in_map(char tab[11][22], int tmp[9][9])
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (i < 9)
    {
      while (nb < 9)
        {
          if (tab[i + 1][nb + nb + 2] == ' ')
            tmp[i][nb] = 0;
          else
            tmp[i][nb] = tab[i + 1][nb + nb + 2] - '0';
          nb++;
        }
      nb = 0;
      i++;
    }
  return (0);
}

int		get_map(char tab[11][22])
{
  size_t        len;
  ssize_t       read;
  char          *line;
  int		i;

  len = 0;
  i = 0;
  line = NULL;
  if ((read = getline(&line, &len, stdin)) == -1)
    {
      free(line);
      return (1);
    }
  strcpy(tab[i], line);
  i++;
  while (i < 11)
    {
      read = getline(&line, &len, stdin);
      if (read == -1)
	return (2);
      strcpy(tab[i], line);
      i++;
    }
  free(line);
  return (0);
}
