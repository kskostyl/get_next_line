/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 22:26:23 by kskostyl          #+#    #+#             */
/*   Updated: 2019/02/18 22:05:32 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	l;
	char	*s;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = ft_klen(n);
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (s == 0)
		return (0);
	s[l] = 0;
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
		i += 1;
	}
	while (i < l--)
	{
		s[l] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
