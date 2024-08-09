/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:39:13 by vpramann          #+#    #+#             */
/*   Updated: 2023/12/01 19:14:28 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			tmp = (char *)(s + i);
		i++;
	}
	if (s[i] == (char) c)
		tmp = (char *)(s + i);
	return (tmp);
}
