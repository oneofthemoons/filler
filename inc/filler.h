/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:31:09 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/04/10 16:32:04 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H
# include "../gnl/get_next_line.h"
# include <mlx.h>
# define MAX_POINT 1000000
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define PLAYER_COLOR 0x00FF00
# define ENEMY_COLOR 0xFF0000
# define BACKGROUND_COLOR 0xFFEB99
# define FRAME_COLOR 0xC9BB1C

typedef	struct	s_pos
{
	int			x;
	int			y;
	int			min_sum;
}				t_pos;

typedef	struct	s_token
{
	int			hight;
	int			width;
	char		**piece;
}				t_token;

typedef struct	s_image
{
	void		*ptr;
	int32_t		width;
	int32_t		height;
}				t_image;


typedef struct	s_layout
{
	void		*mlx_ptr;
	void		*win_ptr;
	int32_t		cell_range;
	int32_t		point_range;
	int32_t		frame_left;
	int32_t		frame_top;
	int32_t		point_left;
	int32_t		point_top;
	t_image		bcg_img;
}				t_layout;

typedef struct	s_filler
{
	int			hight;
	int			width;
	int			player;
	int			**n_map;
	char		**map;
	char		player_sym;
	char		enemy_sym;
	t_token		token;
	t_layout	layout;
}				t_filler;



typedef struct	s_state
{
	int			is_ps;
	int			is_dot;
	int			is_enemy;
}				t_state;

void			ft_get_token(t_filler *f);
void			ft_get_map(t_filler *f);
void			ft_get_player(char *line, t_filler *f);
void			ft_get_size(char *line, int *hight, int *width);

int				ft_get_sum(t_filler *f, int y, int x);
void			ft_encircling_point(t_filler *f, int y, int x);
void			ft_set_bcoor(t_filler *f, int i, int j, t_pos *mn);
void			ft_get_state(t_filler *f, t_state *st, int i, int j);
void			ft_find_place(t_filler *f);
void			ft_layout_init(t_filler *f);
void			ft_draw_map(t_filler *f);

#endif
