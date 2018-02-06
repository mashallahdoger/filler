/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 18:49:25 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/28 18:49:29 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_viewer.h"

int			this_cmp(const char *needle, const char *haystack)
{
	int	n;

	n = 0;
	while (needle[n] != '\0' && haystack[n] != '\0')
	{
		if (needle[n] != haystack[n])
			return (0);
		n++;
	}
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int	n;

	n = 0;
	if (!haystack)
		return (NULL);
	while (haystack[n] != '\0')
	{
		if (this_cmp(needle, &(haystack[n])))
			return ((char*)(&(haystack[n])));
		n++;
	}
	return (NULL);
}
