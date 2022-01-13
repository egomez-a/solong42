/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:15:16 by egomez-a          #+#    #+#             */
/*   Updated: 2022/01/13 12:37:52 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.map.lines = 0;
	atexit(leaks);
	if (argc == 2)
	{
		if (check_map_extension(argv[1]))
		{
			game.map = read_map(argv[1]);
			game.map.elems.collect = check_map_elements(&game.map);
			open_window(&game);
			game_play(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			printf("Error. Map with wrong extension");
			return (0);
		}
	}
	else
	{
		printf("Error. Wrong number of arguments.\n");
		exit(1);
	}
	return (0);
}
