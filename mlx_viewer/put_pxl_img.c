/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 23:40:53 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/26 17:49:42 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_viewer.h"

int			put_pxl_img(t_coord coord, t_img img)
{
	if (coord.x < 0 || coord.x >= img.lenght ||
		coord.y < 0 || coord.y >= img.height)
		return (0);
	img.data[img.sizeline * coord.y + 4 * coord.x + 0] = coord.color % 0x100;
	img.data[img.sizeline * coord.y + 4 * coord.x + 1] = coord.color /
															0x100 % 0x100;
	img.data[img.sizeline * coord.y + 4 * coord.x + 2] = coord.color / 0x10000;
	return (0);
}
