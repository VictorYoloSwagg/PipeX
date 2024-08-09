/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:37:52 by vpramann          #+#    #+#             */
/*   Updated: 2023/12/04 17:52:59 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*stra;
	unsigned char	*strb;

	i = 0;
	stra = (unsigned char *) dst;
	strb = (unsigned char *) src;
	if (!dst && !src)
		return (dst);
	if (strb < stra)
		while (++i <= len)
			stra[len - i] = strb[len - i];
	else
		while (len-- > 0)
			*(stra++) = *(strb++);
	return (dst);
}
