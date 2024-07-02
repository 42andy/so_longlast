/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:59:15 by astoll            #+#    #+#             */
/*   Updated: 2024/07/02 09:08:00 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	width_calc(char *str)
{
	int	w;

	w = 0;
	while (str[w] != '\0')
		w++;
	if (str[w - 1] == '\n')
		w--;
	return (w);
}

static int	create_line(t_game *game, char *line)
{
	char	**temp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->map_height++;
	temp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	temp[game->map_height] = NULL;
	while (i < game->map_height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	map_calc(t_game *game, char **argv)
{
	char	*map;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("Error\nImpossible d'ouvrir le fichier : %s.\n", argv[1]);
		exit (1);
	}
	while (1)
	{
		map = get_next_line(game->fd);
		if (!create_line(game, map))
			break ;
	}
	close (game->fd);
	if (game->map_height == 0)
	{
		ft_printf("Error\nLe fichier de la carte est vide.\n");
		exit (1);
	}
	game->map_width = width_calc(game->map[0]);
	return (1);
}
