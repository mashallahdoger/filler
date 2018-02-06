/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 21:05:27 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/11 19:18:58 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

# define BUFF_MAX	100000

# define NBZONES	500
# define SIZEZONE	10000

typedef struct		s_input
{
	int				player_id;
	int				get_player_id;
	int				n;
}					t_input;

# define ALLIED		1
# define ENNEMY		2
# define EMPTY		3

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_zone
{
	int				side;
	int				x;
	int				y;
}					t_zone;

typedef struct		s_ia
{
	int				not_set;
	int				pos_x;
	int				pos_y;
	double			distance;
	int				zone;
	t_zone			**tab_zone;
	int				size_tab;
}					t_ia;

typedef struct		s_data
{
	t_input			input;
	char			buffer[BUFF_MAX];
	char			*map;
	int				height_map;
	int				lenght_map;
	char			*piece;
	int				height_piece;
	int				lenght_piece;
	t_ia			ia;
}					t_data;

int					ft_printf(const char *restrict format, ...);
char				*ft_strstr(const char *haystack, const char *needle);
int					get_nbr(char *str);
int					get_input(t_data *data);
int					get_player_id(t_data *data, int *n);
int					get_header(t_data *data, char *name, int *height,
						int *lenght);
int					get_map(t_data *data, int *n);
int					get_piece(t_data *data, int *n);
void				get_best_position(t_data *data);
int					ft_strcmp(char *s1, char *s2);
int					ft_put_err(char *str);
unsigned int		ft_strlen(const char *str);
int					is_better_place(t_data *data, int y, int x);
double				get_dist(int xa, int ya, int xb, int yb);
double				ft_sqrt(int nb);
int					create_zone(t_data *data, int y, int x);
int					recursive_zone(t_data *data, t_zone *zone,
						t_coord coord, int *n);

#endif
