/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 09:22:32 by astoll            #+#    #+#             */
/*   Updated: 2024/07/02 10:04:29 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	confirm_path(int y, int x, t_game *game, char **map_copy)
{
	if (map_copy[y][x] == 'E')
		game->exit_path++;
	if (y < 0 || y >= game->map_height || x < 0 || x >= game->map_width
		|| map_copy[y][x] == '1' || map_copy[y][x] == 'E'
		|| map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'C')
		game->collec_path++;
	map_copy[y][x] = '1';
	confirm_path(y, (x - 1), game, map_copy);
	confirm_path(y, (x + 1), game, map_copy);
	confirm_path((y - 1), x, game, map_copy);
	confirm_path((y + 1), x, game, map_copy);
	return ;
}

static char	**copy_map(char **original_map, int height, int width)
{
	char	**map_copy;
	int		i;
	int		j;

	i = -1;
	map_copy = malloc(height * sizeof(char *));
	if (!map_copy)
		return (NULL);
	while (++i < height)
	{
		map_copy[i] = malloc((width + 1) * sizeof(char));
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		j = -1;
		while (++j < width)
			map_copy[i][j] = original_map[i][j];
		map_copy[i][width] = '\0';
	}
	return (map_copy);
}

static void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

int	check_path_from_start(t_game *game, char **map_copy, int y, int x)
{
	confirm_path(y, x, game, map_copy);
	if (game->colleccount == game->collec_path && game->exit_path)
	{
		free_map_copy(map_copy, game->map_height);
		return (1);
	}
	else
	{
		ft_printf("Error\nIl n'y a pas de chemin valide.\n");
		free_map_copy(map_copy, game->map_height);
		return (0);
	}
}

int	path_check(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game->map, game->map_height, game->map_width);
	if (!map_copy)
	{
		ft_printf("Error\nImpossible d'allouer mémoire.\n");
		return (0);
	}
	game->y_axis = 0;
	while (game->y_axis < game->map_height)
	{
		game->x_axis = 0;
		while (game->x_axis < game->map_width)
		{
			if (game->map[game->y_axis][game->x_axis] == 'P')
				return (check_path_from_start(game, map_copy,
						game->y_axis, game->x_axis));
			game->x_axis++;
		}
		game->y_axis++;
	}
	free_map_copy(map_copy, game->map_height);
	return (0);
}
