/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:53:04 by cmaxime           #+#    #+#             */
/*   Updated: 2017/12/06 14:42:44 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		endian;
	int		size_line;
	int		size_column;
	int		bpp;
}				t_img;

typedef struct	s_pos
{
	int		x;
	int		y;
	int		color;
}				t_pos;

typedef struct	s_cnf
{
	char	**argv;
	int		argc;
	int		current;
	int		scale;
	float	cst1;
	float	cst2;
	float	z;
	int		x;
	int		y;
	int		a_x;
	int		a_y;
	int		z_max;
	int		z_min;
	int		rot;
	double	max_xy;
	double	mid_x;
	double	mid_y;
	t_pos	(*setp)(double, double, double, struct s_cnf);
	int		(*setc)(int, int, int);
}				t_cnf;

typedef struct	s_map
{
	int		**map;
	size_t	x;
	size_t	y;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	t_cnf	cnf;
}				t_mlx;

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		xi;
	int		yi;
	int		e;
}				t_line;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_keyfunct
{
	int		key;
	t_mlx	(*fct)(t_mlx);
}				t_keyfunct;

t_img			set_img_pxl(t_img img, int x, int y, int color);
t_mlx			fdf_init(int size_x, int size_y, char *name, t_map map);
t_map			fdf_map_init(void);
t_mlx			cnf_init(t_mlx mlx, t_map map);
int				fdf_store_map(char *file_name, t_map *map);
t_mlx			set_line(t_mlx img, t_pos p1, t_pos p2);
t_map			fdf_map_cpy(t_map map);
t_pos			setp_parallele(double x, double y, double z, t_cnf c);
t_pos			setp_isometrique(double x, double y, double z, t_cnf c);
t_pos			setp_conique(double x, double y, double z, t_cnf c);
t_mlx			fdf_map_to_img(t_mlx mlx);
t_color			get_color_diff(int color1, int color2);
int				setc_rg(int z, int min, int max);
int				setc_rgdegrade(int z, int min, int max);
int				setc_orangepurpledegrade(int z, int min, int max);
int				setc_realistique(int z, int min, int max);
int				setc_ultrarealistique(int z, int min, int max);
t_color			get_converted_color(int color);
int				get_color(int color, double delta, t_color c_color);
t_mlx			fdf_loadnext_map(t_mlx mlx);
t_mlx			fdf_multimap_init(t_mlx mlx, char **argv, int argc);
t_map			free_map(t_map map);
t_mlx			execute_action(int key, t_mlx mlx);
void			refresh_term(t_mlx mlx);
void			term_putmap_name(char *name);
void			term_putsize_map(int x, int y, int z);
void			term_options(void);
int				term_prog_usage(void);
int				term_bad_map(void);

#endif
