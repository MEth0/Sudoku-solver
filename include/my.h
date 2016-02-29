/*
** my.h for sudoku in /home/simon_z/rendu/Rush/sudoki-bi
**
** Made by Morgan SIMON
** Login   <simon_z@epitech.net>
**
** Started on  Fri Feb 26 20:50:19 2016 Morgan SIMON
** Last update Sat Feb 27 13:49:39 2016 Morgan SIMON
*/

#ifndef MY_H_
# define MY_H_

int     parseur(char map[11][22]);
int	calc(int map[9][9], int pos);
int     check_double(int map[9][9]);
int     get_in_map(char tab[11][22], int tmp[9][9]);
int     get_map(char tab[11][22]);
int     what_do_i_print(int map[9][9]);

#endif /* !MY_H_ */
