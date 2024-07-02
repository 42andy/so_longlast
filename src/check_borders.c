/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:42:07 by astoll            #+#    #+#             */
/*   Updated: 2024/07/02 09:01:34 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_verti_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
		{
			ft_printf("Error\nLes bords doivent être composés de '1'.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_hori_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1')
		{
			ft_printf("Error\nLa première ligne doit être composée de '1'.\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < game->map_width)
	{
		if (game->map[game->map_height - 1][i] != '1')
		{
			ft_printf("Error\nLa dernière ligne doit être composée de '1'.\n");
			return (0);
		}
		i++;
	}
	return (1);
}
