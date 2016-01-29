/*
** get_next_line.h for  in /home/thomas/Documents/epitech/CPE_2015_getnextline
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Mon Jan  4 17:50:09 2016 thomas
** Last update Thu Jan  7 15:44:43 2016 thomas
*/

#ifndef READ_SIZE
# define READ_SIZE 1000
#endif

#ifndef __GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char		*get_next_line(const int fd);

#endif
