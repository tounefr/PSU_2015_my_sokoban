/*
** map_parsing2.c for  in /home/thomas/Documents/epitech/PSU_2015_my_sokoban
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Thu Jan  7 15:17:24 2016 thomas
** Last update Fri Jan 15 09:34:54 2016 thomas
*/

#include "sokoban.h"

void	parse_map(struct s_lines *map_content)
{
  parse_map_size_lines_map(map_content);
  parse_map_allowed_chars(map_content);
  parse_map_walls(map_content);
  parse_map_boxes(map_content);
}

char	nbr_obstacles_boxe(int line, int col, char **map)
{
  int	nbr;

  nbr = 0;
  if (map[line+1][col] == '#')
    nbr++;
  if (map[line-1][col] == '#')
    nbr++;
  if (map[line][col-1] == '#')
    nbr++;
  if (map[line][col+1] == '#')
    nbr++;
  return (nbr);
}

char	in_corner(int line, int col, char **map)
{
  if (map[line][col+1] == '#' && map[line+1][col] == '#')
    return (1);
  if (map[line][col+1] == '#' && map[line-1][col] == '#')
    return (1);
  if (map[line-1][col] == '#' && map[line][col-1] == '#')
    return (1);
  if (map[line][col-1] == '#' && map[line-1][col] == '#')
    return (1);
  return (0);
}

char	game_is_blocked(char **map)
{
  int	map_width;
  int	map_height;
  int	line;
  int	col;

  get_map_infos(map, &map_width, &map_height);
  line = 0;
  while (line < map_height)
    {
      col = 0;
      while (col < map_width)
	{
	  if (map[line][col] == 'X')
	    {
	      if (nbr_obstacles_boxe(line, col, map) > 2)
		return (1);
	      if (in_corner(line, col, map))
		return (1);
	    }
	  col++;
	}
      line++;
    }
  return (0);
}
