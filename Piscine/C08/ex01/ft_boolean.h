/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabed <yabed@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:19:42 by yabed             #+#    #+#             */
/*   Updated: 2024/01/15 13:10:34 by yabed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>
# define EVEN(x) x % 2 == 0
# define EVEN_MSG "I have an even number of arguments."
# define ODD_MSG "I have an odd number of arguments."
# define TRUE 1
# define FALSE 0
# define SUCCESS 0

typedef int	t_bool;
#endif