/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 09:55:23 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/07 15:11:43 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			all_is_recovered(t_data *data)
{
	int		ret;
	t_input	*i;

	data->input.n = 0;
	i = &data->input;
	if (i->get_player_id && (ret = get_player_id(data, &i->n)) <= 0)
		return (ret);
	if ((ret = get_header(data, "Plateau ", &data->height_map,
			&data->lenght_map)) <= 0)
		return (ret);
	if ((ret = get_map(data, &i->n)) <= 0)
		return (ret);
	if ((ret = get_header(data, "Piece ", &data->height_piece,
			&data->lenght_piece)) <= 0)
		return (ret);
	data->piece = &data->buffer[i->n];
	if ((ret = get_piece(data, &i->n)) <= 0)
		return (ret);
	i->get_player_id = 0;
	return (1);
}

int			get_input(t_data *data)
{
	int		size_read;
	char	buffer[BUFF_MAX];
	int		n;
	int		m;
	int		ret;

	m = 0;
	while ((size_read = read(0, buffer, BUFF_MAX)))
	{
		n = 0;
		while (n < size_read)
		{
			data->buffer[m + n] = buffer[n];
			n += 1;
		}
		data->buffer[m + n] = '\0';
		m += n;
		if ((ret = all_is_recovered(data)))
			return (ret);
	}
	return (ft_put_err("Nothing to read in the input"));
}
