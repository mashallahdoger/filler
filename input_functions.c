/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 10:02:41 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/26 13:28:35 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_player_id(t_data *data, int *n)
{
	char	*p;

	p = data->buffer;
	while (p[*n] && p[*n] != '\n')
		*n += 1;
	if (!p[*n] || (*n = 0))
		return (0);
	if (ft_strcmp(p, "$$$ exec p"))
		return (ft_put_err("Problem in player id"));
	*n = 10;
	if (p[*n] == '1' && (*n += 1))
		data->input.player_id = 'o';
	else if (p[*n] == '2' && (*n += 1))
		data->input.player_id = 'x';
	else
		return (ft_put_err("Problem in player id"));
	if (ft_strcmp(&p[*n], " : [./adauchy.filler]\n"))
		return (ft_put_err("Problem in player id"));
	*n += 22;
	return (1);
}

int			get_header(t_data *data, char *name, int *height, int *lenght)
{
	char	*p;
	int		m;
	int		*n;

	n = &data->input.n;
	p = data->buffer;
	m = *n;
	while (p[m] && p[m] != '\n')
		m += 1;
	if (!p[m] || (m = 0))
		return (0);
	if (ft_strcmp(&p[*n], name))
		return (ft_put_err("Error in header"));
	*n += ft_strlen(name);
	*height = get_nbr(&p[*n]);
	while (p[*n] >= '0' && p[*n] <= '9' && (*n += 1))
		m += 1;
	if (p[*n] != ' ' || m > 7 || !(*height) || !(*n += 1) || (m = 0))
		return (ft_put_err("Error in header"));
	*lenght = get_nbr(&p[*n]);
	while (p[*n] >= '0' && p[*n] <= '9' && (*n += 1))
		m += 1;
	if (ft_strcmp(&p[*n], ":\n") || m > 7 || !(*lenght) || !(*n += 2))
		return (ft_put_err("Error in header"));
	return (1);
}

int			get_line_map(int m, char *p, int lenght, char **map)
{
	int		c;
	int		n;

	c = 0;
	while (p[c] && p[c] != '\n')
		c += 1;
	if (!p[c] || (c = 0))
		return (0);
	if (!m)
		*map = &p[c];
	if (get_nbr(p) != m)
		return (ft_put_err("Error in line map"));
	while (p[c] >= '0' && p[c] <= '9')
		c += 1;
	if (p[c] != ' ' || c != 3)
		return (ft_put_err("Error in line map"));
	n = -1;
	while ((n += 1) >= 0 && p[++c] != '\n')
		if (p[c] != '.' && p[c] != 'o' && p[c] != 'O' &&
				p[c] != 'x' && p[c] != 'X')
			return (ft_put_err("Error in line map"));
	if (n != lenght)
		return (ft_put_err("Error in line map"));
	return (1);
}

int			get_map(t_data *data, int *n)
{
	int		m;
	char	*p;
	int		ret;

	m = *n;
	p = data->buffer;
	while (p[m] && p[m] != '\n')
		m += 1;
	if (!p[m] || !(m = -1))
		return (0);
	if (ft_strcmp(&p[*n], "    ") || !(*n += 4))
		return (ft_put_err("Error in map format"));
	while (++m < data->lenght_map)
		if (p[*n + m] - '0' != m % 10)
			return (ft_put_err("Error in map format"));
	*n += m + 1;
	m = -1;
	while (++m < data->height_map)
	{
		if ((ret = get_line_map(m, &p[*n], data->lenght_map,
						&data->map)) <= 0)
			return (ret);
		*n += data->lenght_map + 5;
	}
	return (1);
}

int			get_piece(t_data *data, int *n)
{
	int		h;
	int		l;
	char	*p;

	h = 0;
	p = data->buffer;
	while (h < data->height_piece)
	{
		l = -1;
		while ((l += 1) >= 0 && p[*n] && p[*n] != '\n')
		{
			if (p[*n] != '.' && p[*n] != '*')
				return (ft_put_err("Error in piece format"));
			*n += 1;
		}
		if (!p[*n])
			return (0);
		if (l != data->lenght_piece)
			return (ft_put_err("Error in piece format"));
		*n += 1;
		h += 1;
	}
	if (!p[*n])
		return (1);
	return (0);
}
