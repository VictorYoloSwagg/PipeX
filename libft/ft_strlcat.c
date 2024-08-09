/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:10:25 by vpramann          #+#    #+#             */
/*   Updated: 2023/11/30 16:46:42 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	
	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	unsigned int	len;
	unsigned int	i1;
	unsigned int	i2;

	i1 = 0;
	i2 = 0;
	len = 0;
	while (dest[i2])
		i2++;
	while (src[len])
		len++;
	if (dstsize <= i2)
		return (dstsize + len);
	else
		len = len + i2;
	while (src[i1] && i2 < dstsize - 1)
	{
		dest[i2] = src[i1];
		i1++;
		i2++;
	}
	dest[i2] = '\0';
	return (len);
}
