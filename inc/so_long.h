/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:53:35 by astoll            #+#    #+#             */
/*   Updated: 2024/06/17 11:45:52 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../utils/get_next_line/get_next_line.h"
# include "../utils/mlx/mlx.h"

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collec;
	void	*img_exit;
	char	**map;

	int		fd;	
	int		player_x;
	int		player_y;
	int		playercount;
	int		colleccount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		map_width;
	int		map_height;
	int		collectibles;
	int		steps;
	int		exit_path;
	int		collec_path;
}	t_game;

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);

int		ft_printf(const char *format, ...);

void	create_game(t_game *game);
int		close_game(t_game *game);
void	map_check(t_game *game);
int		check_verti_borders(t_game *game);
int		check_hori_borders(t_game *game);
int		path_check(t_game *game);
int		keyboard(int key, t_game *game);
int		map_calc(t_game *game, char **argv);
void	create_window(t_game *game);

void	place_wall(t_game *game, int height, int width);
void	place_floor(t_game *game, int height, int width);
void	place_player(t_game *game, int height, int width);
void	place_collectible(t_game *game, int height, int width);
void	place_exit(t_game *game, int height, int width);

#endif