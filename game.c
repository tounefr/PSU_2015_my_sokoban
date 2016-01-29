/*
** game.c for  in /home/thomas/Documents/epitech/PSU_2015_my_sokoban
** 
** Made by thomas
** Login   <thomas@epitech.net>
** 
** Started on  Thu Jan  7 14:38:25 2016 thomas
** Last update Sun Jan 17 16:39:16 2016 thomas
*/

#include "sokoban.h"

void	on_key(int key, char ***map_content, char **original_map)
{
  int	player_row;
  int	player_col;

  get_pos_player(*map_content, &player_col, &player_row);
  if (key == KEY_UP)
    move_top(player_row, player_col, *map_content, original_map);
  else if (key == KEY_DOWN)
    move_bottom(player_row, player_col, *map_content, original_map);
  else if (key == KEY_LEFT)
    move_left(player_row, player_col, *map_content, original_map);
  else if (key == KEY_RIGHT)
    move_right(player_row, player_col, *map_content, original_map);
  else if (key == ' ')
    reset_game(map_content, original_map);
}

char	game_test_win(char **map_content, char **original_map)
{
  int	row;
  int	col;

  row = 0;
  while (map_content[row])
    {
      col = 0;
      while (map_content[row][col])
	{
	  if (original_map[row][col] == 'O' && map_content[row][col] != 'X')
	    return (0);
	  col++;
	}
      row++;
    }
  return (1);
}

void	reset_game(char ***map_content, char **original_map)
{
  *map_content = clone_double_array(original_map);
  display_map(*map_content);
}

void	game(char **map, char **original_map)
{
  int	key;
  int	map_width;
  int	map_height;

  initscr();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  get_map_infos(original_map, &map_width, &map_height);
  while (!game_test_win(map, original_map) && !game_is_blocked(map))
    {
      display_map(map);
      key = getch();
      on_key(key, &map, original_map);
    }
  display_map(map);
  if (game_test_win(map, original_map))
    mvprintw(LINES/2 + map_height+2, COLS/2 - map_width-2, "VOUS AVEZ GAGNE !");
  else if (game_is_blocked(map))
    mvprintw(LINES/2 + map_height+2, COLS/2 - map_width-2, "JEU BLOQUE !");
  key = getch();
  endwin();
}
