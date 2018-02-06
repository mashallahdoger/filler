/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:19:11 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/06 20:37:45 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

double			get_dist(int xa, int ya, int xb, int yb)
{
	int		dist_x;
	int		dist_y;

	dist_x = xa - xb;
	dist_y = ya - yb;
	return (ft_sqrt(dist_x * dist_x + dist_y * dist_y));
}
