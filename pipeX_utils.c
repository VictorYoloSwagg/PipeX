/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeX_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:40:16 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/19 19:07:17 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tabs(char **tab1, char **tab2)
{
	free_tab(tab1);
	free_tab(tab2);
}

void	free_strs(char *str1, char *str2)
{
	free(str1);
	free(str2);
}

char	*get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*cmdpath;
	char	**cmds;

	i = -1;
	if (!cmd)
		return (NULL);
	paths = ft_split(get_paths(envp), ':');
	cmds = ft_split(cmd, ' ');
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		cmdpath = ft_strjoin(path, cmds[0]);
		if (access(cmdpath, F_OK | X_OK) == 0)
			return (free(path), free_tab(cmds), cmdpath);
		free_strs(cmdpath, path);
	}
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(cmds[0], 2);
	ft_putstr_fd("\n", 2);
	free_tabs(cmds, paths);
	return (NULL);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;

	if (!cmd)
		return ;
	cmds = ft_split(cmd, ' ');
	path = find_cmd_path(cmd, envp);
	if (execve(path, cmds, envp) == -1)
	{
		free_tab(cmds);
		exit(0);
	}
}
