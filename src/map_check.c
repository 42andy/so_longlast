/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:04:52 by astoll            #+#    #+#             */
/*   Updated: 2024/07/02 09:09:40 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	is_map_rectangular(t_game *game)
{
	int	i;
	int	length;
	int	line_length;

	i = 0;
	length = ft_strlen(game->map[0]);
	while (i < game->map_height)
	{
		line_length = ft_strlen(game->map[i]);
		if (i == game->map_height - 1 && game->map[i][line_length - 1] != '\n')
			line_length++;
		if (line_length != length)
		{
			ft_printf("Error\nLa map n'est pas rectangulaire.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static void	count_checker(t_game *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf("Error\nCaractère invalide dans la map.\n");
		close_game(game);
	}
	if (game->map[height][width] == 'C')
			game->colleccount++;
	if (game->map[height][width] == 'P')
			game->playercount++;
	if (game->map[height][width] == 'E')
			game->exitcount++;
}

static int	cara_check(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map_height - 1)
	{
		width = 0;
		while (width < game->map_width - 1)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->colleccount >= 1
			&& game->exitcount == 1))
	{
		ft_printf("Error\nNombre de joueur, collec. ou sortie faux.\n");
		return (0);
	}
	return (1);
}

void	map_check(t_game *game)
{
	int	cara_ok;
	int	is_hori_ok;
	int	is_verti_ok;
	int	is_rectang;
	int	path_ok;

	cara_ok = cara_check(game);
	if (!cara_ok)
		close_game(game);
	is_hori_ok = check_hori_borders(game);
	if (!is_hori_ok)
		close_game(game);
	is_verti_ok = check_verti_borders(game);
	if (!is_verti_ok)
		close_game(game);
	is_rectang = is_map_rectangular(game);
	if (!is_rectang)
		close_game(game);
	path_ok = path_check(game);
	if (!path_ok)
		close_game(game);
}
