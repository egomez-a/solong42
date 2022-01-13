/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:59:18 by egomez-a          #+#    #+#             */
/*   Updated: 2022/01/13 12:35:34 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_game(t_game *game)
{
	memclear(game->map.map2d);
	mlx_destroy_image(game->mlx, game->img.collect);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.hero);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_window(game->mlx, game->window.reference);
	free(game->mlx);
	exit(1);
}

void	game_move(int keynote, t_game *game)
{
	if (keynote == W)
	{
		game->hero.y -= 1;
		hero_up(game);
	}
	else if (keynote == S)
	{
		game->hero.y += 1;
		hero_down(game);
	}
	else if (keynote == A)
	{
		game->hero.x -= 1;
		hero_left(game);
	}
	else if (keynote == D)
	{
		game->hero.x += 1;
		hero_right(game);
	}
}

int	key_press(int keynote, t_game *game)
{
	if ((keynote == ESC) || (game->endgame == 42))
		close_game(game);
	else
	{
		game_move(keynote, game);
		if (game->endgame != 42)
			printf("Moves: %d, collectibless pending %d\n", game->moves,
				game->map.elems.collect);
	}
	return (0);
}

void	game_play(t_game *game)
{
	mlx_key_hook(game->window.reference, key_press, game);
}
