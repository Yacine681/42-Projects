/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:37:27 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:32:17 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate(t_parma *ptr, double angle)
{
	double	olddirx;
	double	oldplanx;

	oldplanx = ptr->plane_x;
	olddirx = ptr->dir_x;
	ptr->dir_x = ptr->dir_x * cos(angle) - \
		ptr->dir_y * sin(angle);
	ptr->dir_y = olddirx * sin(angle) + ptr->dir_y * cos(angle);
	ptr->plane_x = ptr->plane_x * cos(angle) - \
		ptr->plane_y * sin(angle);
	ptr->plane_y = oldplanx * sin(angle) + ptr->plane_y * cos (angle);
}

void	forword(t_parma *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x + ptr->dir_x)][(int)(\
		ptr->pos_y + ptr->dir_y)] == '0')
	{
		ptr->pos_x += ptr->dir_x * ptr->m_speed;
		ptr->pos_y += ptr->dir_y * ptr->m_speed;
	}
}

void	backword(t_parma *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x - ptr->dir_x)][(int)(\
		ptr->pos_y - ptr->dir_y)] == '0')
	{
		ptr->pos_x -= ptr->dir_x * ptr->m_speed;
		ptr->pos_y -= ptr->dir_y * ptr->m_speed;
	}
}

void	right(t_parma *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x)][(int)(\
		ptr->pos_y + ptr->dir_y + ptr->plane_y)] == '0')
	{
		ptr->pos_y += ptr->plane_y * ptr->m_speed;
		ptr->pos_x += ptr->plane_x * ptr->m_speed;
	}
}

void	left(t_parma *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x)][(int)(\
		ptr->pos_y + ptr->dir_y - ptr->plane_y)] == '0')
	{
		ptr->pos_y -= ptr->plane_y * ptr->m_speed;
		ptr->pos_x -= ptr->plane_x * ptr->m_speed;
	}
}
