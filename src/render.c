/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrickard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:44:00 by hrickard          #+#    #+#             */
/*   Updated: 2019/04/11 17:44:01 by hrickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int32_t		ft_expose_render(void *filler)
{
	char		*line;
	t_filler	*f;

	f = (t_filler*)filler;
	if (f->draw)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
		ft_get_map(f);
		ft_draw_map(f);
		ft_make_heat_map(f);
		get_next_line(0, &line);
		ft_get_size(line, &(f->token.hight), &(f->token.width));
		ft_strdel(&line);
		ft_get_token(f);
		ft_find_place(f);
		if (get_next_line(0, &line) < 1)
		{
			ft_free_maps(f);
			f->draw = 0;
		}
		if (line)
			ft_strdel(&line);
	}
	return (0);
}

int32_t		ft_key(int32_t key, void *filler)
{
	t_filler	*f;

	f = (t_filler*)filler;
	if (key == 53)
		ft_close(filler);
	return (0);
}

int32_t		ft_close(void *filler)
{
	t_filler	*f;

	f = (t_filler*)f;
	exit(0);
	return (0);
}
