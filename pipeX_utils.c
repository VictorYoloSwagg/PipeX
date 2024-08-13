/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeX_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:40:16 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/13 19:50:45 by vpramann         ###   ########.fr       */
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

char	*getpaths(char **envp)
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

char	*findpath(char *cmd, char **envp)
{
	int	i;
	char **paths;
	char *path;
	char *cmdpath;
	char **cmds;
	
	i = 0;
	paths = ft_split(getpaths(envp), ':');
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
	free_tab(paths);
	return (NULL);
}

int	exec(char *cmd, char **argv, char **envp)
{
	char	**cmds;
	char	*path;

	cmds = ft_split(cmd, ' ');
	path = findpath(cmds[0], envp);
	/*execve(path, cmds, envp);*/
	if (execve(path, argv, envp) == -1)
	{
		free_tab(cmds);
		/*exit(0);*/
		return(0);
	}
	return (1);
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