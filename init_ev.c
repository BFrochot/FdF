/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:36:29 by bfrochot          #+#    #+#             */
/*   Updated: 2017/02/02 17:32:21 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initev(t_env *ev)
{
	ev->mlx = NULL;
	ev->win = NULL;
	ev->array = NULL;
	ev->rx = -60;
	ev->ry = 60;
	ev->winx = ev->len * 86;
	ev->winy = ev->len * 43;
	ev->winx = (ev->winx > 2560 ? 2560 : ev->winx);
	ev->winx = (ev->winx < 960 ? 960 : ev->winx);
	ev->winy = (ev->winy > 1440 ? 1440 : ev->winy);
	ev->winy = (ev->winy < 540 ? 540 : ev->winy);
	ev->zoom = ev->winx / (2.5 * ev->len);
	ev->p = ev->zoom / 10;
	ev->tx = 0;
	ev->ty = ev->len / 2;
	ev->px = 0;
	ev->py = 0;
	ev->mx = 0;
	ev->my = 0;
	ev->c = 1;
}
