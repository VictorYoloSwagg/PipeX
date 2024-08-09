/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:14:59 by vpramann          #+#    #+#             */
/*   Updated: 2023/12/01 19:51:15 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	size;
	char	*s;
	char	*d;

	size = 0;
	d = (char *) dst;
	s = (char *) src;
	if (!dst && !src)
		return (dst);
	while (size < n)
	{
		*(unsigned char *)(dst + size) = *(unsigned char *)(src + size);
		size++;
	}
	return (dst);
}
