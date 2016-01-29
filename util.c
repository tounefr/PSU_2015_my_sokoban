/*
** util.c for  in /home/thomas/Documents/epitech/PSU_2015_my_sokoban
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Wed Jan  6 12:29:59 2016 thomas
** Last update Thu Jan  7 14:58:37 2016 thomas
*/

#include "sokoban.h"

void	fatal_error(char *str)
{
  write(2, str, my_strlen(str));
  exit(1);
}

void	my_malloc(void **datas, unsigned int size)
{
  if (0 == (*datas = malloc(size)))
    fatal_error("malloc error\n");
}

char	in_buffer(char c, char *str)
{
  int	i;
  int	str_len;

  str_len = my_strlen(str);
  i = 0;
  while (i < str_len)
    {
      if (c == str[i])
	return (1);
      i++;
    }
  return (0);
}

char	**clone_double_array(char **double_array)
{
  char	**cloned;
  int	i;

  i = 0;
  while (double_array[i])
    i++;
  my_malloc((void*)&cloned, sizeof(char*)*i);
  i = 0;
  while (double_array[i])
    {
      cloned[i] = my_strdup(double_array[i]);
      i++;
    }
  cloned[i] = '\0';
  return (cloned);
}

unsigned int get_pos(char c, char *str)
{
  int	i;
  int	str_len;

  str_len = my_strlen(str);
  i = 0;
  while (i < str_len)
    {
      if (c == str[i])
	return (i);
      i++;
    }
  return (-1);
}
