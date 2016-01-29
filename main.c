/*
** main.c for  in /home/thomas/Documents/epitech
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Mon Jan  4 10:00:21 2016 thomas
** Last update Thu Jan  7 19:02:52 2016 thomas
*/

#include "sokoban.h"

int			main(int argc, char **argv)
{
  struct s_lines	*map_content;
  char			**map_content_chars;
  char			**map_original_content_chars;

  if (argc != 2)
    return (my_putstr("Usage: ./my_sokoban map.txt\n"));
  map_content = get_map_content(argv[1]);
  map_content_chars = linked_list_to_chars(map_content);
  map_original_content_chars = clone_double_array(map_content_chars);
  parse_map(map_content);
  game(map_content_chars, map_original_content_chars);
  free(map_content_chars);
  free(map_original_content_chars);
  free(map_content);
  return (0);
}
