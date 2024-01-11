/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:26:07 by yabed             #+#    #+#             */
/*   Updated: 2024/01/11 11:39:30 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*ret[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	int			rd_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd_bytes = read(fd, buff, BUFFER_SIZE);
	while (rd_bytes > 0)
	{
		buff[rd_bytes] = '\0';
		ft_add_buff(&ret[fd], buff);
		if (ft_strchr_gnl(ret[fd], '\n') != -1)
			return (ft_get_line(&ret[fd]));
		rd_bytes = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_get_line(&ret[fd]));
}
