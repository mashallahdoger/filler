/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:32:24 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/26 17:36:14 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_viewer.h"

int			init_img(t_img *img, void *mlx, int lenght, int height)
{
	if ((img->img = mlx_new_image(mlx, lenght, height)) == NULL)
		return (-1);
	if ((img->data = mlx_get_data_addr(img->img, &img->bpb,
		&img->sizeline, &img->endian)) == NULL)
		return (-1);
	img->lenght = lenght;
	img->height = height;
	return (0);
}

int			init_mlx(t_data *data)
{
	if ((data->mlx = mlx_init()) == NULL)
		return (-1);
	if ((data->win = mlx_new_window(data->mlx, LENGHT_WIN,
					HEIGHT_WIN, "FDF")) == NULL)
		return (-1);
	if (init_img(&data->img, data->mlx, LENGHT_WIN, HEIGHT_WIN) == -1)
		return (-1);
	return (0);
}
