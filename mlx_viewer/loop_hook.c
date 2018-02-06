/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:37:39 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/28 20:22:06 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_viewer.h"

int			get_color(char *map, int y, int x, int lenght)
{
	char	carac;

	carac = map[x + 4 + y * (lenght + 5)];
	if (carac == '.')
		return (0x000000);
	if (carac == 'X')
		return (0xA19B00);
	if (carac == 'x')
		return (0xFFFF00);
	if (carac == 'O')
		return (0x0038D2);
	if (carac == 'o')
		return (0x1EE2F7);
	return (0xFFFFFF);
}

void		print_fight(t_data *data)
{
	int			y;
	int			x;
	t_coord		size;
	t_coord		pos;
	int			color;

	y = 0;
	size.x = data->lenght_pix / data->lenght;
	size.y = data->height_pix / data->height;
	while (y < data->height)
	{
		x = 0;
		pos.y = y * size.y;
		while (x < data->lenght)
		{
			color = get_color(data->map, y, x, data->lenght);
			pos.x = x * size.x;
			print_square(pos, size, color, data->img);
			x += 1;
		}
		y += 1;
	}
}

int			loop_hook(t_data *data)
{
	if (!data->end && get_buffer(data) == -1)
		exit(0);
	if (!data->end)
		print_fight(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}
