/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:57:54 by vpramann          #+#    #+#             */
/*   Updated: 2023/12/04 16:21:57 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*front_trim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	in_set;

	i = 0;
	j = 0;
	in_set = 0;
	while (s1[i])
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
			break ;
		i++;
	}
	return ((char *) s1 + i);
}

static char	*back_trim(char const *s1, char const *set, char const *begin)
{
	int	i;
	int	j;
	int	in_set;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (s1 + i >= begin)
	{
		in_set = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				in_set = 1;
			j++;
		}
		if (!in_set)
			break ;
		i--;
	}
	if (s1 + i < begin)
		return ((char *) begin);
	return ((char *) s1 + i);
}

static char	*fill_str(char const *begin, char const *end)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (end - begin + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (begin + i <= end)
	{
		str[i] = begin[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*begin;
	char	*end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	begin = front_trim(s1, set);
	end = back_trim(s1, set, s1);
	if (!s1[0] || end < begin)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	else
		str = fill_str(begin, end);
	if (!str)
		return (NULL);
	return (str); 
}
