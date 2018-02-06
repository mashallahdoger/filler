/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_viewer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 16:23:19 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/28 20:20:39 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_viewer.h"

int			main(void)
{
	t_data data;

	data.lenght = 0;
	data.height = 0;
	data.buffer[0] = 0;
	data.end = 0;
	if (init_mlx(&data) == -1)
		return (-1);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
}
