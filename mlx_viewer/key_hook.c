/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:38:25 by adauchy           #+#    #+#             */
/*   Updated: 2017/12/26 17:47:09 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_viewer.h"

int			key_hook(int keycode, t_data *data)
{
	(void)data;
	if (keycode == ECHAP)
		exit(0);
	return (0);
}
