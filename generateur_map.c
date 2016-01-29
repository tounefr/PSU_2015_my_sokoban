/*
** generateur_map.c for  in /home/thomas/Documents/epitech/PSU_2015_my_sokoban
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Fri Jan  8 17:23:45 2016 thomas
** Last update Fri Jan  8 17:28:25 2016 thomas
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
  int	map_width;
  int	map_height;
  char	**map;

  if (argc != 3)
    {
      printf("Usage ./generateur_map map_width map_height\n");
      exit(1);
    }

  map_width = atoi(argv[1]);
  map_height = atoi(argv[2]);

  memset(map, 0, ((sizeof(char*) * map_height) + 1));

  return (0);
}
