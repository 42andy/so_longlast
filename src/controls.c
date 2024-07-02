/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:57:46 by astoll            #+#    #+#             */
/*   Updated: 2024/07/02 09:04:55 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	move_up(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	if (game->map[game->player_y - 1][game->player_x] == 'C')
	{
		game->collectibles--;
	}
	game->map[game->player_y - 1][game->player_x] = 'P';
	game->steps++;
	create_game(game);
}

static void	move_down(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	if (game->map[game->player_y + 1][game->player_x] == 'C')
	{
		game->collectibles--;
	}
	game->map[game->player_y + 1][game->player_x] = 'P';
	game->steps++;
	create_game(game);
}

static void	move_left(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	if (game->map[game->player_y][game->player_x - 1] == 'C')
	{
		game->collectibles--;
	}
	game->map[game->player_y][game->player_x - 1] = 'P';
	game->steps++;
	create_game(game);
}

static void	move_right(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	if (game->map[game->player_y][game->player_x + 1] == 'C')
	{
		game->collectibles--;
	}
	game->map[game->player_y][game->player_x + 1] = 'P';
	game->steps++;
	create_game(game);
}

int	keyboard(int key, t_game *game)
{
	if (key == 53)
		close_game(game);
	if (game->collectibles == 0
		&& ((key == 124 && game->map[game->player_y][game->player_x + 1] == 'E')
		|| (key == 125 && game->map[game->player_y + 1][game->player_x] == 'E')
		|| (key == 123 && game->map[game->player_y][game->player_x - 1] == 'E')
		|| (key == 126
				&& game->map[game->player_y - 1][game->player_x] == 'E')))
	{
		ft_printf("Vous avez gagné !\n");
		close_game(game);
	}
	if (key == 126 && game->map[game->player_y - 1][game->player_x] != '1'
		&& game->map[game->player_y - 1][game->player_x] != 'E')
		move_up(game);
	if (key == 123 && game->map[game->player_y][game->player_x - 1] != '1'
		&& game->map[game->player_y][game->player_x - 1] != 'E')
		move_left(game);
	if (key == 125 && game->map[game->player_y + 1][game->player_x] != '1'
		&& game->map[game->player_y + 1][game->player_x] != 'E')
		move_down(game);
	if (key == 124 && game->map[game->player_y][game->player_x + 1] != '1'
		&& game->map[game->player_y][game->player_x + 1] != 'E')
		move_right(game);
	return (0);
}
