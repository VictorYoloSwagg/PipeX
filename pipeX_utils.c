/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeX_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:40:16 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/09 21:20:11 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*getpaths(char *cmd, char **envp)
{
	int	i;
	char **paths;
	char	*path;
	char **cmds;
	char	*cmdpath;
	
	i = 0;
	while (envp[i])
	{
		if (*envp[i] == 'P' && *envp[i] + 1 == 'A' && *envp[i] + 2 == 'T' && *envp[i] + 3 == 'H' && *envp[i] + 4 == '=')
		{
			paths = ft_split(envp[i] + 5, ':');
			break;
		}
		i++;
	}
	i = 0;
	cmds = ft_split(cmd, ' ');
	while(paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		cmdpath = ft_strjoin(path, cmds[0]);
		if (access(cmdpath, F_OK | X_OK) == 0)
		{
			free_tab(cmds);
			return (cmdpath);
		}
		free(cmdpath);
		i++;
	}
	free_tab(cmds);
	free_tab(paths)
	return (NULL);
}

void	exec(char *cmd, char **envp)
{
	char	**cmds;
	char	*path;

	cmds = ft_split(cmd, ' ');
	path = get_path(cmds[0], envp);
	if (execve(path, cmds, envp) == -1)
	{
		free_tab(cmds);
		exit(0);
	}
}

/*char	*findpath(char *envpaths)
{
	char	**paths;
	char	*path;
	int	i;

	i = 0;
	paths = ft_split(envpaths, ':');
	while (paths[i])
	
}*/

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

void	execcmd(char *paths, char *argv, char **envp)
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
}