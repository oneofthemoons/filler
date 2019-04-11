/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrown-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:45:18 by lbrown-b          #+#    #+#             */
/*   Updated: 2019/04/10 15:45:22 by lbrown-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	ft_make_heat_map(t_filler *f)
{
	int32_t i;
	int32_t	j;
	int32_t	n;

	n = f->hight > f->width ? f->hight : f->width;
	while (n--)
	{
		i = -1;
		while (++i < f->hight)
		{
			j = -1;
			while (++j < f->width)
				ft_encircling_point(f, i, j);
		}
	}
}

void	ft_create_maps(t_filler *f)
{
	int32_t	i;

	f->map = (char**)malloc(sizeof(char*) * f->hight);
	i = -1;
	ft_bzero(f->map, f->hight * sizeof(char*));
	while (++i < f->hight)
		f->map[i] = (char*)malloc(sizeof(char) * f->width);
	f->n_map = (int32_t**)malloc(sizeof(int32_t*) * f->hight);
	i = -1;
	ft_bzero(f->n_map, f->hight * sizeof(int32_t*));
	while (++i < f->hight)
		f->n_map[i] = (int32_t*)malloc(sizeof(int32_t) * f->width);
}

void	ft_free_maps(t_filler *f)
{
	int32_t i;

	i = -1;
	while (++i < f->hight)
		free(f->map[i]);
	i = -1;
	while (++i < f->hight)
		free(f->n_map[i]);
}

void	ft_set_base(t_filler *f)
{
	char		*line;

	get_next_line(0, &line);
	ft_get_player(line, f);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_get_size(line, &f->hight, &f->width);
	ft_strdel(&line);
	ft_create_maps(f);
}

int32_t	main(void)
{
	char		*line;
	t_filler	f;

	ft_set_base(&f);
	ft_layout_init(&f);
	f.draw = 1;
	mlx_hook(f.layout.win_ptr, 17, 0, ft_close, (void*)&f);
	mlx_key_hook(f.layout.win_ptr, ft_key, (void*)&f);
	mlx_loop_hook(f.layout.mlx_ptr, ft_expose_render, (void*)&f);
	mlx_loop(f.layout.mlx_ptr);
}
