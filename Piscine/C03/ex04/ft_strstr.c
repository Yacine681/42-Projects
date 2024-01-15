/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 09:54:19 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 12:57:44 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	a;
	int	b;

	a = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[a] != '\0')
	{
		b = 0;
		while (str[a + b] != '\0' && str[a + b] == to_find[b])
		{
			if (to_find[b + 1] == '\0')
				return (&str[a]);
				b++;
		}
		a++;
	}
	return (0);
}