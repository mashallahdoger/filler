/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 23:04:16 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/21 18:10:45 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_itoa(char *str, long long nb, int size, int *pos)
{
	unsigned long long	un_nb;
	long long			div;
	int					count;
	int					n;

	count = 0;
	n = 1;
	div = 1;
	un_nb = nb;
	if ((nb < 0) && (str[count] = '-') && (str += 1) && (*pos += 1))
		un_nb = -nb;
	while (un_nb / div >= 10 && (div *= 10))
		n += 1;
	n = size - n;
	while (count < n)
		str[count++] = '0';
	while (div)
	{
		str[count] = un_nb / div % 10 + '0';
		div /= 10;
		count += 1;
	}
	*pos += count;
}
