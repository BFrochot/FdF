/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:35:55 by bfrochot          #+#    #+#             */
/*   Updated: 2017/02/02 18:08:26 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(int x, int y, int color, t_env *ev)
{
	if (x < 0 || y < 0)
		return ;
	if (x > ev->winx || y > ev->winy)
		return ;
	ev->p_img = mlx_get_data_addr(ev->img, &(ev->bpp), &(ev->s_line),
	&(ev->ed));
	((int *)ev->p_img)[x + y * ev->s_line / 4] = color;
}

void	draw_line(double *pts1, double *pts2, t_env *ev)
{
	double i;
	double m;

	pts1[2] = fabs(pts1[2]) > fabs(pts2[2]) ? pts2[2] : pts1[2];
	if (pts1[0] == pts2[0] && pts1[1] == pts2[1])
		put_pixel(pts1[0], pts1[1], colorline(pts1[2], ev), ev);
	else if (fabs(pts1[0] - pts2[0]) >= fabs(pts1[1] - pts2[1]))
	{
		i = pts1[0] <= pts2[0] ? pts1[0] - 1 : pts2[0] - 1;
		while (++i <= (pts1[0] <= pts2[0] ? pts2[0] : pts1[0]) && (m = i *
			(pts1[1] - pts2[1]) / (pts1[0] - pts2[0]) + (pts2[1] * pts1[0] -
			pts2[0] * pts1[1]) / (pts1[0] - pts2[0])) <= ev->winy)
			put_pixel(i, m, ev->c == 1 ? colorline(pts1[2], ev) :
			colorline2(pts1[2], ev), ev);
	}
	else
	{
		i = pts1[1] <= pts2[1] ? pts1[1] - 1 : pts2[1] - 1;
		while (++i <= (pts1[1] <= pts2[1] ? pts2[1] : pts1[1]) && (m = i *
			(pts1[0] - pts2[0]) / (pts1[1] - pts2[1]) - (pts2[1] * pts1[0] -
			pts2[0] * pts1[1]) / (pts1[1] - pts2[1])) <= ev->winx)
			put_pixel(m, i, ev->c == 1 ? colorline(pts1[2], ev) :
			colorline2(pts1[2], ev), ev);
	}
}
