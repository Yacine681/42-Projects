/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:57:11 by yabed             #+#    #+#             */
/*   Updated: 2022/07/07 14:51:24 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/so_long.h"

char	*get_next_line(int fd)
{
	char	*str;
	char	*buffer;
	int		nbchar;

	buffer = ft_calloc((2), sizeof(char));
	str = NULL;
	nbchar = read(fd, buffer, 1);
	if (nbchar > 0)
		str = ft_calloc((2), sizeof(char));
	while (nbchar > 0 && buffer[0] != '\n')
	{
		str = ft_strjoin(str, buffer);
		nbchar = read(fd, buffer, 1);
	}
	if (buffer[0] == '\n')
		str = ft_strjoin(str, "\n");
	free(buffer);
	return (str);
}
