/*
** linked_lists.c for  in /home/thomas/Documents/epitech/PSU_2015_my_sokoban
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Wed Jan  6 12:29:39 2016 thomas
** Last update Fri Jan 15 08:49:57 2016 thomas
*/

#include "sokoban.h"

struct s_lines		*new_s_lines_elem(char *line)
{
  struct s_lines	*lines;

  my_malloc((void*)&lines, sizeof(struct s_lines));
  lines->line = line;
  lines->nbr_lines = 1;
  lines->length = my_strlen(line);
  lines->next = NULL;
  return (lines);
}

char			append_line(struct s_lines **head, char *line)
{
  struct s_lines	*tmp;

  if (*head == NULL)
    {
      *head = new_s_lines_elem(line);
      return (1);
    }
  tmp = *head;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new_s_lines_elem(line);
  (*head)->nbr_lines += 1;
  return (1);
}

char	**linked_list_to_chars(struct s_lines *lines)
{
  char	**lines_chars;
  int	i;

  i = 0;
  my_malloc((void*)&lines_chars, (sizeof(char*) * (lines->nbr_lines + 1)));
  while (lines != 0)
    {
      lines_chars[i++] = lines->line;
      lines = lines->next;
    }
  return (lines_chars);
}
