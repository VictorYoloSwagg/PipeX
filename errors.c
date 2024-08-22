/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:31:36 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/22 20:38:12 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_errors(int i, char **cmds, char *file1)
{
	if (i == 0)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(cmds[0], 2);
		ft_putstr_fd("\n", 2);
	}
	else if (i == 1)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putstr_fd(file1, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (i == 2)
	{
		ft_putstr_fd("pipex: wrong number of arguments", 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putstr_fd(file1, 2);
		ft_putstr_fd("\n", 2);
	}
	return ;
}
