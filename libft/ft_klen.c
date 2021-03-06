/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_klen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:06:20 by kskostyl          #+#    #+#             */
/*   Updated: 2019/02/22 21:07:51 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_klen(int a)
{
	int		len;

	len = 0;
	if (a == 0)
		return (1);
	if (a < len)
		len += 1;
	while (a != 0)
	{
		a = a / 10;
		len++;
	}
	return (len);
}
