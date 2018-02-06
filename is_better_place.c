/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_better_place.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:28:00 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/07 15:37:28 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_zone(t_data *data, int y, int x)
{
	int		n;
	int		m;

	n = -1;
	while (++n < data->ia.size_tab)
	{
		m = 0;
		while (++m <= data->ia.tab_zone[n][0].side)
		{
			if (data->ia.tab_zone[n][m].x == x &&
				data->ia.tab_zone[n][m].y == y)
				return (n);
		}
	}
	return (create_zone(data, y, x));
}

int			get_distance_ennemy(int y, int x, t_zone *zone)
{
	int		n;
	double	distance;
	double	tmp;

	n = 1;
	distance = 0;
	while (n <= zone[0].side)
	{
		if (zone[n].side == ENNEMY)
		{
			tmp = get_dist(x, y, zone[n].x, zone[n].y);
			if (distance == 0 || tmp < distance)
				distance = tmp;
		}
		n += 1;
	}
	return (distance);
}

int			is_better_zone(t_data *data, int y, int x)
{
	char	carac;
	int		zone;
	double	distance;

	carac = data->map[(x >= 0 ? x :
			(x + data->lenght_map)) + 4 + (y >= 0 ? y :
			(y + data->height_map)) * (data->lenght_map + 5)];
	if (carac != '.' && carac != '*')
		return (0);
	zone = get_zone(data, y, x);
	if (zone == -1)
		return (0);
	distance = get_distance_ennemy(y, x, data->ia.tab_zone[zone]);
	if (data->ia.zone == -1 || data->ia.tab_zone[data->ia.zone][0].side <
		data->ia.tab_zone[zone][0].side ||
		(data->ia.zone == zone &&
		distance < data->ia.distance))
	{
		data->ia.zone = zone;
		data->ia.distance = distance;
		return (1);
	}
	return (0);
}

int			is_better_place(t_data *data, int y, int x)
{
	int		j;
	int		i;
	int		better;

	better = 0;
	j = -1;
	while (++j < data->height_piece)
	{
		i = -1;
		while (++i < data->lenght_piece)
		{
			if (data->piece[i + j * (data->lenght_piece + 1)] == '*' &&
				is_better_zone(data, (y + j >= 0 ? (y + j) :
				(y + j + data->height_map)),
				(x + i >= 0 ? (x + i) : (x + i + data->lenght_map))))
				better = 1;
		}
	}
	if (data->ia.not_set && !(data->ia.not_set = 0))
		return (1);
	return (better);
}
