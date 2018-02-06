/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:01:20 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/28 20:20:05 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_viewer.h"

void			replace_map(char *buffer)
{
	char	*ptr;
	int		n;

	ptr = ft_strstr(buffer, "Plateau");
	ptr = ft_strstr(ptr, "Piece");
	n = 0;
	while (ptr[n])
	{
		buffer[n] = ptr[n];
		n += 1;
	}
	buffer[n] = 0;
}

void			get_pos_map(t_data *data, char *ptr)
{
	int		n;
	int		count;

	n = 0;
	count = 0;
	while (count < 2)
	{
		while (ptr[n] != '\n')
			n += 1;
		n += 1;
		count += 1;
	}
	data->map = &ptr[n];
}

void			get_dimensions(t_data *data, char *map)
{
	int		n;

	n = 0;
	while (map[n] != ' ')
		n += 1;
	n += 1;
	data->height = get_nbr(&map[n]);
	while (map[n] != ' ')
		n += 1;
	n += 1;
	data->lenght = get_nbr(&map[n]);
	data->height_pix = HEIGHT_WIN;
	data->lenght_pix = data->lenght * data->height_pix / data->height;
	if (data->height < data->lenght)
	{
		data->lenght_pix = LENGHT_WIN;
		data->height_pix = data->height * data->lenght_pix / data->lenght;
	}
}

int				get_map(t_data *data)
{
	int			size_read;
	char		*map;
	char		*piece;
	char		buffer[BUFF_MAX + 1];

	while (42)
	{
		map = ft_strstr(data->buffer, "Plateau");
		piece = ft_strstr(map, "Piece");
		if (map && piece)
		{
			get_pos_map(data, map);
			if (!data->lenght && !data->height)
				get_dimensions(data, map);
			return (0);
		}
		if (!(size_read = read(0, buffer, BUFF_MAX)))
			return ((data->end = 1));
		if (size_read == -1)
			return (-1);
		buffer[size_read] = 0;
		ft_strcat(data->buffer, buffer);
	}
}

int				get_buffer(t_data *data)
{
	if (data->buffer[0])
		replace_map(data->buffer);
	if (get_map(data) == -1)
		return (-1);
	return (0);
}
