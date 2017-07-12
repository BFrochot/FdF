/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:20:17 by bfrochot          #+#    #+#             */
/*   Updated: 2017/02/02 16:40:42 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdfinit3(double mx, double my, t_env *ev, int *cord)
{
	double pts1[3];
	double pts2[3];

	pts1[0] = mx;
	pts1[1] = my - ft_atoi(ev->array[cord[0]][cord[1]]) * ev->p * 10 / ev->len;
	pts1[2] = ft_atoi(ev->array[cord[0]][cord[1]]);
	pts2[0] = mx - sin(ev->rx * 2 * M_PI / 360) * ev->zoom;
	pts2[1] = my + cos(ev->rx * 2 * M_PI / 360) * ev->zoom -
	ft_atoi(ev->array[cord[0]][cord[1] + 1]) * ev->p * 10 / ev->len;
	pts2[2] = ft_atoi(ev->array[cord[0]][cord[1] + 1]);
	draw_line(pts1, pts2, ev);
}

void	fdfinit2(double mx, double my, t_env *ev, int *cord)
{
	double pts1[3];
	double pts2[3];

	pts1[0] = mx;
	pts1[1] = my - ft_atoi(ev->array[cord[0]][cord[1]]) * ev->p * 10 / ev->len;
	pts1[2] = ft_atoi(ev->array[cord[0]][cord[1]]);
	pts2[0] = mx + sin(ev->ry * 2 * M_PI / 360) * ev->zoom;
	pts2[1] = my - ft_atoi(ev->array[cord[0] + 1][cord[1]]) * ev->p * 10
	/ ev->len - cos(ev->ry * 2 * M_PI / 360) * ev->zoom;
	pts2[2] = ft_atoi(ev->array[cord[0] + 1][cord[1]]);
	draw_line(pts1, pts2, ev);
}

void	fdfinit4(t_env *ev, int *cord, double mx, double my)
{
	if (ev->array[cord[0] + 1] && ev->array[cord[0] + 1][cord[1]])
		fdfinit2(mx, my, ev, cord);
	if (ev->array[cord[0]][cord[1] + 1])
		fdfinit3(mx, my, ev, cord);
	++cord[1];
}

int		fdfinit(t_env *ev)
{
	int		cord[2];

	cord[0] = -1;
	ev->px = ev->tx * ev->zoom;
	ev->py = ev->ty * ev->zoom;
	while (ev->array[++cord[0]] && (cord[1] = 0) == 0)
	{
		ev->px = ev->px + sin(ev->ry * 2 * M_PI / 360) * ev->zoom;
		ev->py = ev->py - cos(ev->ry * 2 * M_PI / 360) * ev->zoom;
		ev->mx = ev->px;
		ev->my = ev->py;
		while (ev->array[cord[0]][cord[1]])
		{
			ev->mx = ev->mx - sin(ev->rx * 2 * M_PI / 360) * ev->zoom;
			ev->my = ev->my + cos(ev->rx * 2 * M_PI / 360) * ev->zoom;
			if (ev->mx <= -(ev->winx / ev->len) || ev->mx >= ev->winx)
				++cord[1];
			else if (ev->my <= -(ev->winy / ev->len) || ev->my >= ev->winy)
				++cord[1];
			else
				fdfinit4(ev, cord, ev->mx, ev->my);
		}
	}
	mlx_put_image_to_window(ev->mlx, ev->win, ev->img, 50, 50);
	return (printcontrol(ev));
}
