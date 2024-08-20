/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 21:28:06 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/20 21:29:28 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	print_errors(int i, char **cmds, char *file1)
{
	if (i == 0)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(cmds[0], 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putstr_fd(file1, 2);
		ft_putstr_fd("\n", 2);
	}
	return ;
}