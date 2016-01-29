/*
** map_parsing.c for  in /home/thomas/Documents/epitech/PSU_2015_my_sokoban
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Wed Jan  6 12:28:55 2016 thomas
** Last update Thu Jan  7 18:59:47 2016 thomas
*/

#include "sokoban.h"

void		parse_map_size_lines_map(struct s_lines *map_content)
{
  unsigned int	length;

  if (map_content->nbr_lines < 3)
    fatal_error("Map error: number lines must be > 3 !\n");
  length = map_content->length;
  while (map_content)
    {
      if (map_content->length != length || map_content->length < 3)
	fatal_error("Map error: wrong length line\n");
      map_content = map_content->next;
    }
}

void	parse_map_allowed_chars(struct s_lines *map_content)
{
  int	i;

  while (map_content)
    {
      i = 0;
      while (i < map_content->length)
	{
	  if (!in_buffer(map_content->line[i], MAP_ALLOWED_CHARS))
	    fatal_error("Map error: unallowed char in map file\n");
	  i++;
	}
      map_content = map_content->next;
    }
}

void	parse_map_walls(struct s_lines *map_content)
{
  int	i;
  int	i2;
  int	nbr_lines;

  nbr_lines = map_content->nbr_lines;
  i = 0;
  while (map_content)
    {
      if (i == 0 || i == (nbr_lines-1))
	{
	  i2 = 0;
	  while (i2 < map_content->length)
	    {
	      if (map_content->line[i2] != '#')
		fatal_error("Map error: wall\n");
	      i2++;
	    }
	}
      if (map_content->line[0] != '#' ||
	  map_content->line[map_content->length-1] != '#')
	fatal_error("Map error: wall\n");
      i++;
      map_content = map_content->next;
    }
}

void	init_map_parsing(struct s_map_parsing *map_parsing)
{
  map_parsing->nb_boxes = 0;
  map_parsing->nb_storages_locations = 0;
  map_parsing->nb_players = 0;
}

void				parse_map_boxes(struct s_lines *map_content)
{
  struct s_map_parsing		map_parsing;
  int				i;

  init_map_parsing(&map_parsing);
  while (map_content)
    {
      i = 0;
      while (i < map_content->length)
	{
	  if (map_content->line[i] == 'O')
	    map_parsing.nb_storages_locations++;
	  else if (map_content->line[i] == 'X')
	    map_parsing.nb_boxes++;
	  else if (map_content->line[i] == 'P')
	    map_parsing.nb_players++;
	  i++;
	}
      map_content = map_content->next;
    }
  if (map_parsing.nb_players != 1)
    fatal_error("Map error: nb players != 1\n");
  if (map_parsing.nb_boxes != map_parsing.nb_storages_locations ||
      map_parsing.nb_boxes < 1)
    fatal_error("Map error: nb storages != nb_boxes\n");
}
