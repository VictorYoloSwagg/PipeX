/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:13:35 by vpramann          #+#    #+#             */
/*   Updated: 2023/11/30 16:42:54 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) b;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	b = (void *) str;
	return (b);
}
