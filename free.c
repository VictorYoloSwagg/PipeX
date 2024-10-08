/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:28:06 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/20 22:13:32 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_tabs(char **tab1, char **tab2)
{
	if (!tab1 | !tab2)
		return ;
	free_tab(tab1);
	free_tab(tab2);
}

void	free_strs(char *str1, char *str2)
{
	if (!str1 | !str2)
		return ;
	free(str1);
	free(str2);
}
