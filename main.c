/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 21:04:36 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/11 19:18:15 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			init_tab_zone(t_data *data)
{
	int		n;

	if (!(data->ia.tab_zone =
				(t_zone**)malloc(NBZONES * sizeof(t_zone*))))
		return (-1);
	n = 0;
	while (n < 500)
	{
		if (!(data->ia.tab_zone[n] =
					(t_zone*)malloc(SIZEZONE * sizeof(t_zone))))
			return (-1);
		n += 1;
	}
	return (0);
}

void		reset_ia(t_ia *ia)
{
	ia->not_set = 1;
	ia->distance = 0;
	ia->zone = -1;
	ia->size_tab = 0;
}

int			main(void)
{
	t_data	data;

	if (init_tab_zone(&data) == -1)
		return (-1);
	data.input.get_player_id = 1;
	while (42)
	{
		if (get_input(&data) == -1)
			return (-1);
		reset_ia(&data.ia);
		get_best_position(&data);
		ft_printf("%d %d\n", data.ia.pos_y, data.ia.pos_x);
	}
	return (0);
}
