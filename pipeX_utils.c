/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeX_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:40:16 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/19 17:17:25 by vpramann         ###   ########.fr       */
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

/*int	*getaccess(char *file1, char *file2)
{
	
	int fds[2];
	
	if (!access(file1, F_OK))
		return(NULL);
	else
	{
		access(file1, R_OK);
		fds[0] = open(file1, O_RDONLY | O_APPEND, 0777);
	}	
	if (!access(file2, F_OK))
		open(file2, O_WRONLY | O_APPEND | O_CREAT, 0777);
	else
	{
		access(file2, W_OK);
		fds[1] = open(file2, O_WRONLY | O_APPEND, 0777);
	}	
}*/

/*void	execcmd(char *paths, char *argv, char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = malloc(sizeof(char) * (ft_strlen(paths[i])));
	path = paths[i];
	while (path)
	{
		if (execve(path, &argv, envp) != -1)
			return(1);
		i++;
		free(path);
		path = paths[i];
		
	}
	return(0);
}*/