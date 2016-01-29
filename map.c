/*
** map.c for  in /home/thomas/Documents/epitech/PSU_2015_my_sokoban
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Thu Jan  7 14:42:21 2016 thomas
** Last update Fri Jan 15 08:50:18 2016 thomas
*/

#include "sokoban.h"

struct s_lines		*get_map_content(char *path)
{
  int			fd;
  char			*content;
  struct s_lines	*lines;

  lines = NULL;
  if (-1 == (fd = open(path, O_RDONLY)))
    fatal_error("Map file doesn't exist !\n");
  while ((content = get_next_line(fd)) != NULL)
    append_line(&lines, content);
  close(fd);
  return (lines);
}

void	get_map_infos(char **map, int *map_width, int *map_height)
{
  int	i;
  int	i2;

  i = 0;
  while (map[i])
    {
      i2 = 0;
      while (map[i][i2])
	i2++;
      i++;
    }
  *map_width = i2 - 1;
  *map_height = i - 1;
}

void	display_map(char **map)
{
  int	i;
  int	i2;
  int	map_width;
  int	map_height;

  get_map_infos(map, &map_width, &map_height);
  i = 0;
  while (map[i])
    {
      i2 = 0;
      while (map[i][i2])
	{
	  mvaddch((LINES / 2) + i - (map_height / 2),
		  (COLS / 2) + i2 - (map_width / 2), map[i][i2]);
	  i2++;
	}
      i++;
    }
  move(i + 1, 0);
  refresh();
}
