/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 09:00:53 by astoll            #+#    #+#             */
/*   Updated: 2024/06/17 12:28:22 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_args(int argc, char *argv[])
{	
	int	i;

	if (argc != 2)
	{
		ft_printf("Error\nEssayez avec : ./so_long maps/map#.ber.\n");
		exit (1);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
	{
		ft_printf("Error\nL'extension du fichier map doit être un .ber.\n");
		exit (1);
	}
	i = ft_strlen(argv[1]) - 1;
	while (i >= 0 && argv[1][i] != '/')
		i--;
	if (argv[1][i + 1] == '.')
	{
		ft_printf("Error\nLe fichier map ne doit pas commencer par un point.\n");
		exit (1);
	}
}

int	close_game(t_game *game)
{
	int	line;

	line = 0;
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	free(game->mlx_ptr);
	while (line < game->map_height)
		free(game->map[line++]);
	free(game->map);
	ft_printf("Closing game...\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	check_args(argc, argv);
	ft_memset(&game, 0, sizeof(t_game));
	map_calc(&game, argv);
	map_check(&game);
	game.mlx_ptr = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx_ptr,
			(game.map_width * 32),
			(game.map_height * 32), "so_long");
	create_window(&game);
	mlx_key_hook(game.mlx_win, keyboard, &game);
	mlx_hook(game.mlx_win, 17, 0, close_game, &game);
	mlx_loop(game.mlx_ptr);
	exit (0);
	return (0);
}
