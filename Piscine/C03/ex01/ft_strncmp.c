/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:17:55 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 12:57:27 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	a;

	if (n == 0)
		return (0);
	a = 0;
	while (s1[a] == s2[a] && s1[a] && s2[a] && a < n)
		a++;
	if (a == n)
		a--;
	return (s1[a] - s2[a]);
}