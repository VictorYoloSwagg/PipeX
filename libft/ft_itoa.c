/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:36:08 by vpramann          #+#    #+#             */
/*   Updated: 2023/12/04 16:30:59 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_count(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i = 1;
	}
	if (nb == 0)
		i = 1;
	else
	{
		while (nb > 0)
		{
			nb = nb / 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	nb;
	int		neg;

	i = len_count((long) n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	nb = (long) n;
	neg = 0;
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
		neg = 1;
	}
	str[i] = '\0';
	while (i > neg)
	{
		str[i - 1] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	return (str);
}
