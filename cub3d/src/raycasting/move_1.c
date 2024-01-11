/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:36:39 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:32:08 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	start_scane(void *ptr)
{
	t_parma	*start_ptr;

	start_ptr = ptr;
	mlx_clear_window(start_ptr->mlx, start_ptr->win_ptr);
	start_drw(start_ptr);
	return (0);
}

void	move(t_parma *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img.ptr);
	ptr->img.ptr = mlx_new_image(ptr->mlx, ptr->screen_w, \
		ptr->screen_h);
	if (ptr->r_right == 1)
		rotate(ptr, -(ptr->r_angle));
	else if (ptr->r_left == 1)
		rotate(ptr, ptr->r_angle);
	else if (ptr->m_up == 1)
		forword(ptr);
	else if (ptr->m_down == 1)
		backword(ptr);
	else if (ptr->m_right == 1)
		right(ptr);
	else if (ptr->m_left == 1)
		left(ptr);
	mlx_clear_window(ptr->mlx, ptr->win_ptr);
	ptr->x = 0;
	start_scane(ptr);
	mini_map(ptr);
}

int	press(int key, t_parma*ptr)
{
	if (key == 124)
		ptr->r_right = 1;
	else if (key == 123)
		ptr->r_left = 1;
	else if (key == 13)
		ptr->m_up = 1;
	else if (key == 1)
		ptr->m_down = 1;
	else if (key == 2)
		ptr->m_right = 1;
	else if (key == 0)
		ptr->m_left = 1;
	else if (key == 53)
		ft_close(ptr);
	else
		return (1);
	move(ptr);
	return (0);
}

int	release(int key, t_parma *ptr)
{
	if (key == 124)
		ptr->r_right = 0;
	else if (key == 123)
		ptr->r_left = 0;
	else if (key == 13)
		ptr->m_up = 0;
	else if (key == 1)
		ptr->m_down = 0;
	else if (key == 2)
		ptr->m_right = 0;
	else if (key == 0)
		ptr->m_left = 0;
	return (0);
}
