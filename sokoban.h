/*
** sokoban.h for  in /home/thomas/Documents/epitech
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Mon Jan  4 10:00:49 2016 thomas
** Last update Fri Jan 15 09:24:47 2016 thomas
*/

#ifndef __SOKOBAN_H__
# define __SOKOBAN_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "my.h"

# define READ_SIZE 1024
# define MAP_ALLOWED_CHARS "#XOP "

struct			s_lines
{
  char			*line;
  unsigned int		length;
  unsigned int		nbr_lines;
  struct s_lines	*next;
};

struct		s_map_parsing
{
  unsigned int	nb_boxes;
  unsigned int	nb_storages_locations;
  unsigned int	nb_players;
};

char		*get_next_line(const int fd);

/*
** game.c
*/
void	on_key(int key, char ***map_content, char **original_map);
char	game_test_win(char **map_content, char **original_map);
void	reset_game(char ***map_content, char **original_map);
void	game(char **map, char **original_map);

/*
** linked_lists.c
*/
struct s_lines		*new_s_lines_elem(char *line);
char			append_line(struct s_lines **head, char *line);
char	**linked_list_to_chars(struct s_lines *lines);

/*
** map.c
*/
struct s_lines		*get_map_content(char *path);
void	get_map_infos(char **map, int *map_width, int *map_height);
void	display_map(char **map);

/*
** map_parsing.c
*/
void	parse_map_size_lines_map(struct s_lines *map_content);
void	parse_map_allowed_chars(struct s_lines *map_content);
void	parse_map_walls(struct s_lines *map_content);
void	init_map_parsing(struct s_map_parsing *map_parsing);
void	parse_map_boxes(struct s_lines *map_content);

/*
** map_parsing2.c
*/
void	parse_map(struct s_lines *map_content);
char	game_is_blocked(char **map);
char	nbr_obstacles_boxe(int line, int col, char **map);

/*
** movement.c
*/
int	get_pos_player(char **map_content, int *col, int *row);
void	move_left(int player_row, int player_col,
		  char **map_content, char **original_map);
void	move_right(int player_row, int player_col,
		   char **map_content, char **original_map);
void	move_bottom(int player_row, int player_col,
		    char **map_content, char **original_map);
void	move_top(int player_row, int player_col,
		 char **map_content, char **original_map);

/*
** util.c
*/
void	fatal_error(char *str);
void	my_malloc(void **datas, unsigned int size);
char	in_buffer(char c, char *str);
char	**clone_double_array(char **double_array);
unsigned int get_pos(char c, char *str);

#endif
