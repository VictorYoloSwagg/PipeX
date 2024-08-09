/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:31:36 by vpramann          #+#    #+#             */
/*   Updated: 2023/11/21 19:01:16 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nlen;
	char	*str;

	i = 0;
	str = (char *) haystack;
	nlen = ft_strlen(needle);
	if (nlen == 0 || haystack == needle)
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && needle[j] 
			&& str[i + j] == needle[j] && i + j < len)
			j++;
		if (j == nlen)
			return (str + i);
		i++;
	}
	return (0);
}
