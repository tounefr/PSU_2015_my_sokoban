/*
** get_next_line.c for  in /home/thomas/Documents/epitech/CPE_2015_getnextline
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Mon Jan  4 17:49:58 2016 thomas
** Last update Fri Jan  8 18:28:20 2016 thomas
*/

#include "my.h"
#include "get_next_line.h"

char		carriage_return_in(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (i);
      i++;
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	*save = NULL;
  char		*buffer;
  int		i;
  static int	readv = 42;

  if ((0 == (buffer = malloc(READ_SIZE + 1))) || ((readv == 0 && !save)))
    return (NULL);
  if ((readv = read(fd, buffer, READ_SIZE)) == -1)
    return (NULL);
  save = my_strcat(save, buffer);
  if ((i = carriage_return_in(save)))
    {
      save[i] = '\0';
      buffer = save;
      save = &save[i + 1];
      return (buffer);
    }
  if (readv == 0)
    {
      buffer = save;
      save = NULL;
      return (buffer);
    }
  return (get_next_line(fd));
}
