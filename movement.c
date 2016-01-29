/*
** movement.c for  in /home/thomas/Documents/epitech/PSU_2015_my_sokoban
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Thu Jan  7 14:37:41 2016 thomas
** Last update Fri Jan 15 08:50:40 2016 thomas
*/

#include "sokoban.h"

int	get_pos_player(char **map_content, int *col, int *row)
{
  int	i;
  int	i2;

  i = 0;
  while (map_content[i])
    {
      i2 = 0;
      while (map_content[i][i2])
	{
	  if (map_content[i][i2] == 'P')
	    {
	      *col = i2;
	      *row = i;
	      return (1);
	    }
	  i2++;
	}
      i++;
    }
  fatal_error("Cannot get player position !\n");
  return (-1);
}

void	move_left(int player_row, int player_col,
		  char **map_content, char **original_map)
{
  if (player_col > 0 && map_content[player_row][player_col-1] != '#')
    {
      if (map_content[player_row][player_col-1] == 'X')
	{
	  if (map_content[player_row][player_col-2] != '#' &&
	      map_content[player_row][player_col-2] != 'X')
	    {
	      map_content[player_row][player_col-1] = 'P';
	      if (original_map[player_row][player_col] == 'O')
		map_content[player_row][player_col] = 'O';
	      else
		map_content[player_row][player_col] = ' ';
	      map_content[player_row][player_col-2] = 'X';
	    }
	}
      else
	{
	  map_content[player_row][player_col-1] = 'P';
	  if (original_map[player_row][player_col] == 'O')
	    map_content[player_row][player_col] = 'O';
	  else
	    map_content[player_row][player_col] = ' ';
	}
    }
}

void	move_right(int player_row, int player_col,
		   char **map_content, char **original_map)
{
  if (map_content[player_row][player_col+1] != '#')
    {
      if (map_content[player_row][player_col+1] == 'X')
	{
	  if (map_content[player_row][player_col+2] != '#' &&
	      map_content[player_row][player_col+2] != 'X')
	    {
	      map_content[player_row][player_col+1] = 'P';
	      if (original_map[player_row][player_col] == 'O')
		map_content[player_row][player_col] = 'O';
	      else
		map_content[player_row][player_col] = ' ';
	      map_content[player_row][player_col+2] = 'X';
	    }
	}
      else
	{
	  map_content[player_row][player_col+1] = 'P';
	  if (original_map[player_row][player_col] == 'O')
	    map_content[player_row][player_col] = 'O';
	  else
	    map_content[player_row][player_col] = ' ';
	}
    }
}

void	move_bottom(int player_row, int player_col,
		    char **map_content, char **original_map)
{
  if (map_content[player_row+1][player_col] != '#')
    {
      if (map_content[player_row+1][player_col] == 'X')
	{
	  if (map_content[player_row+2][player_col] != '#' &&
	      map_content[player_row+2][player_col] != 'X')
	    {
	      map_content[player_row+1][player_col] = 'P';
	      if (original_map[player_row][player_col] == 'O')
		map_content[player_row][player_col] = 'O';
	      else
		map_content[player_row][player_col] = ' ';
	      map_content[player_row+2][player_col] = 'X';
	    }
	}
      else
	{
	  map_content[player_row+1][player_col] = 'P';
	  if (original_map[player_row][player_col] == 'O')
	    map_content[player_row][player_col] = 'O';
	  else
	    map_content[player_row][player_col] = ' ';
	}
    }
}

void	move_top(int player_row, int player_col,
		 char **map_content, char **original_map)
{
  if (map_content[player_row-1][player_col] != '#')
    {
      if (map_content[player_row-1][player_col] == 'X')
	{
	  if (map_content[player_row-2][player_col] != '#' &&
	      map_content[player_row-2][player_col] != 'X')
	    {
	      map_content[player_row-1][player_col] = 'P';
	      if (original_map[player_row][player_col] == 'O')
		map_content[player_row][player_col] = 'O';
	      else
		map_content[player_row][player_col] = ' ';
	      map_content[player_row-2][player_col] = 'X';
	    }
	}
      else
	{
	  map_content[player_row-1][player_col] = 'P';
	  if (original_map[player_row][player_col] == 'O')
	    map_content[player_row][player_col] = 'O';
	  else
	    map_content[player_row][player_col] = ' ';
	}
    }
}
