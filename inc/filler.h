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
# define FRAME_COLOR 0x808080

typedef	struct	s_pos
{
	int32_t		x;
	int32_t		y;
	int32_t		min_sum;
}				t_pos;

typedef	struct	s_token
{
	int32_t		hight;
	int32_t		width;
	char		**piece;
}				t_token;

typedef struct	s_image
{
	void		*ptr;
	int32_t		width;
	int32_t		height;
}				t_image;

typedef struct	s_score
{
	int32_t		player;
	int32_t		enemy;
}				t_score;

typedef struct	s_ipos2d
{
	int32_t		x;
	int32_t		y;
}				t_ipos2d;

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
	int32_t		hight;
	int32_t		width;
	int32_t		player;
	int32_t		**n_map;
	char		**map;
	char		player_sym;
	char		enemy_sym;
	t_token		token;
	t_layout	layout;
	int8_t		draw;
}				t_filler;

typedef struct	s_state
{
	int32_t		is_ps;
	int32_t		is_dot;
	int32_t		is_enemy;
}				t_state;

int32_t			ft_close(void *filler);
int32_t			ft_key(int32_t key, void *filler);
int32_t			ft_expose_render(void *filler);
int32_t			ft_get_sum(t_filler *f, int32_t y, int32_t x);
void			ft_get_map(t_filler *f);
void			ft_draw_map(t_filler *f);
void			ft_get_token(t_filler *f);
void			ft_free_maps(t_filler *f);
void			ft_find_place(t_filler *f);
void			ft_layout_init(t_filler *f);
void			ft_make_heat_map(t_filler *f);
void			ft_get_player(char *line, t_filler *f);
void			ft_encircling_point(t_filler *f, int32_t y, int32_t x);
void			ft_get_size(char *line, int32_t *hight, int32_t *width);
void			ft_set_bcoor(t_filler *f, int32_t i, int32_t j, t_pos *mn);
void			ft_get_state(t_filler *f, t_state *st, int32_t i, int32_t j);

#endif
