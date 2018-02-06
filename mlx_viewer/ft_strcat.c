/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:49:05 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/28 18:49:05 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

void		ft_strcat(char *dest, char *src)
{
	int	n;
	int	m;

	n = 0;
	m = ft_strlen(dest);
	while (src[n])
	{
		dest[m] = src[n];
		n += 1;
		m += 1;
	}
	dest[m] = 0;
}
