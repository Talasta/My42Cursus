/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:20:34 by cmaxime           #+#    #+#             */
/*   Updated: 2018/02/15 19:04:13 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ps_main.h"
# include <mlx.h>

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		endian;
	int		size_line;
	int		size_column;
	int		bpp;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_list		*cmd;
	t_data		*data;
	int			status;
	int			count;
}				t_mlx;

typedef struct	s_pos
{
	int		x;
	int		y;
	int		color;
}				t_pos;

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		xi;
	int		yi;
	int		e;
}				t_line;

t_mlx			ps_mlx_init(t_data *data, t_list *cmd);
t_mlx			ps_data_to_img(t_mlx mlx);
t_img			line(t_img img, t_pos p1, t_pos p2, int color);
t_img			set_img_pxl(t_img img, int x, int y, int color);
t_pos			set_t_pos(int x, int y);
int				ps_execute_action(t_mlx *mlx);
void			ps_get_statusinfo(t_mlx *mlx);
int				refresh(void *param);
int				actions(int key_hook, void *param);
t_op			*ps_get_op_lst(void);
void			ps_free_cmd(t_list *elem);

int				ps_opexe(t_data *data);
int				ps_opexe_view(t_data *data);
int				ps_error(void);
#endif
