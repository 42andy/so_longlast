/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:58:39 by astoll            #+#    #+#             */
/*   Updated: 2024/07/02 09:06:40 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	place_fond(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_floor, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	create_game(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	place_fond(game);
	while (height < game->map_height)
	{
	width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				place_wall(game, height, width);
			if (game->map[height][width] == '0')
				place_floor(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'C')
				place_collectible(game, height, width);
			if (game->map[height][width] == 'E')
				place_exit(game, height, width);
			width++;
		}
		height++;
	}
	ft_printf("Nombre de pas : %i\n", game->steps);
}

static void	create_images(t_game *game)
{
	int	i;
	int	j;

	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/wall.xpm", &i, &j);
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/floor.xpm", &i, &j);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/player.xpm", &i, &j);
	game->img_collec = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/collec.xpm", &i, &j);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/exit.xpm", &i, &j);
}

void	create_window(t_game *game)
{
	game->collectibles = game->colleccount;
	create_images(game);
	create_game(game);
}
