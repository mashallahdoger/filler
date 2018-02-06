/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:43:49 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/06 20:40:31 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

double		ft_sqrt(int nb)
{
	double	sqrt;

	sqrt = 0;
	while (sqrt * sqrt < nb)
		sqrt += 1;
	while (sqrt * sqrt > nb)
		sqrt -= 0.1;
	return (sqrt);
}
