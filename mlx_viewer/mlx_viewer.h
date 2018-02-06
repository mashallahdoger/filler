/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_viewer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:29:08 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/11 19:02:55 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_VIEWER_H
# define MLX_VIEWER_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define LENGHT_WIN	900
# define HEIGHT_WIN 900

# define ECHAP		53

typedef struct		s_coord
{
	int				x;
	int				y;
	int				color;
}					t_coord;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpb;
	int				sizeline;
	int				endian;
	int				height;
	int				lenght;
}					t_img;

# define BUFF_MAX	100000

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	char			buffer[BUFF_MAX + 1];
	char			*map;
	int				height;
	int				lenght;
	int				height_pix;
	int				lenght_pix;
	int				end;
	t_img			img;

}					t_data;

int					init_mlx(t_data *data);
int					loop_hook(t_data *data);
int					key_hook(int keycode, t_data *data);
int					put_pxl_img(t_coord coord, t_img img);
void				print_square(t_coord pos, t_coord size,
						int color, t_img img);
int					get_buffer(t_data *data);
int					get_nbr(char *str);
char				*ft_strstr(const char *haystack, const char *needle);
void				ft_strcat(char *dest, char *src);

#endif
