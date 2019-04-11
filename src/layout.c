/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrickard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:35:18 by hrickard          #+#    #+#             */
/*   Updated: 2019/04/11 14:35:24 by hrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	ft_layout_init(t_filler *f)
{
	f->layout.mlx_ptr = mlx_init();
	f->layout.win_ptr = mlx_new_window(f->layout.mlx_ptr,
		WIN_WIDTH, WIN_HEIGHT, "filler");
	f->layout.bcg_img.ptr = mlx_xpm_file_to_image(f->layout.mlx_ptr,
		"../resources/background2.xpm", &(f->layout.bcg_img.width),
		&(f->layout.bcg_img.height));
	f->layout.cell_range = (WIN_HEIGHT - WIN_HEIGHT / 5) /
		(f->hight > f->width ? f->hight : f->width);
	f->layout.point_range = f->layout.cell_range / 2;
	f->layout.frame_left = (1 * WIN_WIDTH - f->width *
		f->layout.cell_range) / 2;
	f->layout.frame_top = WIN_HEIGHT / 10 + 50;
	f->layout.point_left = f->layout.cell_range / 4;
	f->layout.point_top = f->layout.cell_range / 4;
}

void	ft_draw_cells(t_filler *f)
{
	int32_t	i;
	int32_t	j;

	i = -1;
	while (++i < f->hight + 1)
	{
		j = -1;
		while (++j < f->layout.cell_range * f->width)
			mlx_pixel_put(f->layout.mlx_ptr, f->layout.win_ptr, j +
				f->layout.frame_left, i * f->layout.cell_range +
				f->layout.frame_top, FRAME_COLOR);
	}
	i = -1;
	while (++i < f->width + 1)
	{
		j = -1;
		while (++j < f->layout.cell_range * f->hight)
			mlx_pixel_put(f->layout.mlx_ptr, f->layout.win_ptr, i *
				f->layout.cell_range + f->layout.frame_left, j +
				f->layout.frame_top, FRAME_COLOR);
	}
}

void	ft_draw_background(t_filler *f)
{
	int32_t	i;
	int32_t	j;

	i = -1;
	while (++i < WIN_HEIGHT / f->layout.bcg_img.height + 1)
	{
		j = -1;
		while (++j < WIN_WIDTH / f->layout.bcg_img.width + 1)
			mlx_put_image_to_window(f->layout.mlx_ptr, f->layout.win_ptr,
				f->layout.bcg_img.ptr, j * f->layout.bcg_img.width,
				i * f->layout.bcg_img.height);
	}
}

void	ft_draw_points(t_filler *f, t_score *sc)
{
	t_ipos2d	i;
	t_ipos2d	j;

	*sc = (t_score){0, 0};
	i.y = -1;
	while (++i.y < f->hight)
	{
		i.x = -1;
		while (++i.x < f->width)
			if (f->map[i.y][i.x] != '.')
			{
				j.y = -1;
				while (++j.y < f->layout.point_range)
				{
					j.x = -1;
					while (++j.x < f->layout.point_range)
						mlx_pixel_put(f->layout.mlx_ptr, f->layout.win_ptr,
f->layout.frame_left + i.x * f->layout.cell_range + f->layout.point_left + j.x,
f->layout.frame_top + i.y * f->layout.cell_range + f->layout.point_top + j.y,
f->map[i.y][i.x] == f->player_sym ? PLAYER_COLOR : ENEMY_COLOR);
				}
				sc->player += (f->map[i.y][i.x] == f->player_sym ? 1 : 0);
				sc->enemy += (f->map[i.y][i.x] == f->enemy_sym ? 1 : 0);
			}
	}
}

void	ft_draw_map(t_filler *f)
{
	t_score	sc;

	mlx_clear_window(f->layout.mlx_ptr, f->layout.win_ptr);
	ft_draw_background(f);
	ft_draw_cells(f);
	ft_draw_points(f, &sc);
	mlx_string_put(f->layout.mlx_ptr, f->layout.win_ptr,
f->layout.frame_left / 2, WIN_HEIGHT / 2 - 20, 0xFFFAFA, "PLAYER");
	mlx_string_put(f->layout.mlx_ptr, f->layout.win_ptr,
f->layout.frame_left / 2, WIN_HEIGHT / 2, PLAYER_COLOR, ft_itoa(sc.player));
	mlx_string_put(f->layout.mlx_ptr, f->layout.win_ptr,
WIN_WIDTH - f->layout.frame_left / 2 - 90, WIN_HEIGHT / 2 - 20, 0xFFFAFA,
"ENEMY");
	mlx_string_put(f->layout.mlx_ptr, f->layout.win_ptr,
WIN_WIDTH - f->layout.frame_left / 2 - 90, WIN_HEIGHT / 2,
ENEMY_COLOR, ft_itoa(sc.enemy));
}
