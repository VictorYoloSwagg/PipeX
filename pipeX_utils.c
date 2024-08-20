/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:40:16 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/20 21:36:44 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_paths(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
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
	char	*cmdpath;
	char	**cmds;

	i = -1;
	if (!cmd)
		return (NULL);
	cmds = ft_split(cmd, ' ');
	if (access(cmds[0], F_OK | X_OK) == 0)
		return (cmds[0]);
	if (!envp[0])
		return (NULL);
	paths = ft_split(get_paths(envp), ':');
	while (paths[++i])
	{
		cmdpath = find_path(paths, cmds, i);
		if (cmdpath != NULL)
			return (cmdpath);
		free (cmdpath);
	}
	print_errors(0, cmds, NULL);
	free_tabs(cmds, paths);
	return (NULL);
}

char	*find_path(char **paths, char **cmds, int i)
{
	char	*path;
	char	*cmdpath;
	
	path = ft_strjoin(paths[i], "/");
	cmdpath = ft_strjoin(path, cmds[0]);
	if (access(cmdpath, F_OK | X_OK) == 0)
		return (free(path), free_tabs(cmds, paths), cmdpath);
	free_strs(cmdpath, path);
	return (NULL);
}

void	exec_cmd(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;

	if (!cmd)
		return ;
	if (!envp)
		return ;
	cmds = ft_split(cmd, ' ');
	path = find_cmd_path(cmd, envp);
	if (execve(path, cmds, envp) == -1)
	{
		free_tab(cmds);
		free(path);
		exit(0);
	}
}
