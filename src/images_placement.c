/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_placement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:58:50 by astoll            #+#    #+#             */
/*   Updated: 2024/06/16 16:28:22 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	place_wall(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img_wall, width * 32, height * 32);
}

void	place_floor(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img_floor, width * 32, height * 32);
}

void	place_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img_player, width * 32, height * 32);
	game->player_x = width;
	game->player_y = height;
}

void	place_collectible(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img_collec, width * 32, height * 32);
}

void	place_exit(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img_exit, width * 32, height * 32);
}
