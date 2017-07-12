/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:18:36 by bfrochot          #+#    #+#             */
/*   Updated: 2017/02/02 18:10:16 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		colorline(double i, t_env *ev)
{
	if (i / ev->max <= -1)
		return (0x000099);
	else if (i / ev->max <= -0.6)
		return (0x0000FF);
	else if (i / ev->max <= -0.1)
		return (0x33CCFF);
	else if (i / ev->max <= 0)
		return (0x66FFFF);
	else if (i / ev->max <= 0.02)
		return (0xCCCC33);
	else if (i / ev->max <= 0.1)
		return (0x339933);
	else if (i / ev->max <= 0.28)
		return (0x336600);
	else if (i / ev->max <= 0.46)
		return (0x663300);
	else
		return (0xFFFFFF);
}

int		colorline2(double i, t_env *ev)
{
	if (i / ev->max <= -0.6)
		return (ev->c == 2 ? 0xFFFFFF : 0x123456);
	else if (i / ev->max <= -0.3)
		return (ev->c == 2 ? 0x663300 : 0x66531F);
	else if (i / ev->max <= -0.1)
		return (ev->c == 2 ? 0x336600 : 0x654321);
	else if (i / ev->max <= 0)
		return (ev->c == 2 ? 0x339933 : 0x00146E);
	else if (i / ev->max <= 0.01)
		return (ev->c == 2 ? 0xCCCC33 : 0x0E0FF0);
	else if (i / ev->max <= 0.05)
		return (ev->c == 2 ? 0x66FFFF : 0x198461);
	else if (i / ev->max <= 0.1)
		return (ev->c == 2 ? 0x33CCFF : 0x216194);
	else if (i / ev->max <= 0.3)
		return (ev->c == 2 ? 0x0000FF : 0x485523);
	else
		return (ev->c == 2 ? 0x000099 : 0xF23456);
}
