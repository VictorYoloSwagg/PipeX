/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:38:44 by vpramann          #+#    #+#             */
/*   Updated: 2023/12/04 18:20:40 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_all(char **str, int i)
{
	while (--i >= 0)
		if (str[i])
			free(str[i]);
	return (0);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c && (s[j + 1] == c || s[j + 1] == '\0'))
			i++;
		j++;
	}
	return (i);
}

static void	tab_fill(char *str, char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
}

static int	set_mem(char **tab, char const *s, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (s[i + count] && s[i + count] != c)
			count++;
		if (count > 0)
		{
			tab[j] = malloc(sizeof(char) * (count + 1));
			if (!tab[j])
				return (free_all(tab, j));
			tab_fill(tab[j], s + i, c);
			j++;
			i = i + count;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = word_count(s, c);
	tab = malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	i = set_mem(tab, s, c);
	if (!i)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
