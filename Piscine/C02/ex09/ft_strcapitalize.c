/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:56:32 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 12:57:12 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] >= 'A' && str[a] <= 'Z')
				str[a] = str[a] + 32;
		a++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	ft_strlowcase(str);
	while (str[a] != '\0')
	{
		if (str[a] >= 'a' && str[a] <= 'z')
		{
			if (b == 1)
						str[a] = str[a] - 32;
				b = 0;
		}
		else if (str[a] >= '0' && str[a] <= '9')
				b = 0;
		else
				b = 1;
			a++;
	}
	return (str);
}