/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_zone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 18:12:02 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/07 15:36:26 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			recur_calls(t_data *data, t_zone *zone, t_coord coord, int *n)
{
	int		ret;

	ret = 0;
	coord.y -= 1;
	ret += recursive_zone(data, zone, coord, n);
	coord.y += 1;
	coord.x += 1;
	ret += recursive_zone(data, zone, coord, n);
	coord.x -= 1;
	coord.y += 1;
	ret += recursive_zone(data, zone, coord, n);
	coord.y -= 1;
	coord.x -= 1;
	ret += recursive_zone(data, zone, coord, n);
	return (ret);
}

int			recursive_zone(t_data *data, t_zone *zone, t_coord coord, int *n)
{
	char	carac;

	if (coord.x < 0 || coord.x >= data->lenght_map
		|| coord.y < 0 || coord.y >= data->height_map)
		return (0);
	carac = data->map[coord.x + 4 + coord.y * (data->lenght_map + 5)];
	if (carac == '.')
	{
		zone[++*n].side = EMPTY;
		data->map[coord.x + 4 + coord.y * (data->lenght_map + 5)] = '*';
	}
	else if ((carac == data->input.player_id ||
			carac == data->input.player_id - 32))
		zone[++*n].side = ALLIED;
	else if (carac != '*')
		zone[++*n].side = ENNEMY;
	else
		return (0);
	zone[*n].x = coord.x;
	zone[*n].y = coord.y;
	if (zone[*n].side == EMPTY)
		return (1 + recur_calls(data, zone, coord, n));
	return (1);
}

int			create_zone(t_data *data, int y, int x)
{
	int		ennemy;
	int		size;
	int		n;
	t_coord	coord;

	n = 0;
	ennemy = 0;
	coord.x = (x >= 0 ? x : (x + data->lenght_map));
	coord.y = (y >= 0 ? y : (y + data->height_map));
	size = recursive_zone(data,
			data->ia.tab_zone[data->ia.size_tab], coord, &n);
	data->ia.tab_zone[data->ia.size_tab][0].side = size;
	n = 1;
	while (n <= data->ia.tab_zone[data->ia.size_tab][0].side)
	{
		if (data->ia.tab_zone[data->ia.size_tab][n].side == ENNEMY)
		{
			data->ia.size_tab += 1;
			return (data->ia.size_tab - 1);
		}
		n += 1;
	}
	return (-1);
}
