/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 08:37:56 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/07 15:35:50 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			piece_take_place(t_data *data, int y, int x)
{
	int		j;
	int		i;
	int		contact;
	char	carac_map;
	char	carac_piece;

	j = -1;
	contact = 0;
	while (++j < data->height_piece)
	{
		i = -1;
		while (++i < data->lenght_piece)
		{
			carac_map = data->map[((x + i) >= 0 ? (x + i) :
				((x + i) + data->lenght_map)) + 4 + ((y + j) >= 0 ? (y + j) :
				((y + j) + data->height_map)) * (data->lenght_map + 5)];
			carac_piece = data->piece[i + j * (data->lenght_piece + 1)];
			if (carac_piece == '*' && (carac_map == data->input.player_id ||
						carac_map == data->input.player_id - 32))
				contact += 1;
			else if (carac_piece == '*' && carac_map != '.' && carac_map != '*')
				return (0);
		}
	}
	return ((contact == 1 ? 1 : 0));
}

void		get_best_position(t_data *data)
{
	int		y;
	int		x;

	y = -data->height_piece + 1;
	while (y < data->height_map - data->height_piece + 1)
	{
		x = -data->lenght_piece + 1;
		while (x < data->lenght_map - data->lenght_piece + 1)
		{
			if (piece_take_place(data, y, x) && is_better_place(data, y, x))
			{
				data->ia.pos_x = x;
				data->ia.pos_y = y;
			}
			x += 1;
		}
		y += 1;
	}
}
