/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:40:16 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/01 18:58:15 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpaths(char **envp)
{
	int	i;
	int	j;
	char **paths;
	
	j = 0;
	while (envp[j])
	{
		i = 0;
		while(envp[j][i])
		{
			if (envp[j][i] == 'P' && envp[j][i + 1] == 'A' && envp[j][i + 2] == 'T' && envp[j][i + 3] == 'H' && envp[j][i + 4] == '=')
			{
				paths = ft_split(envp[j] + 5, ':');
				break;
			}
			i++;
		}
		j++;
	}

	free_all(paths);
	return (NULL);
}

char	*findpath(char *envpaths)
{
	char	**paths;
	char	*path;
	int	i;

	i = 0;
	paths = ft_split(envpaths, ':');
	while (paths[i])
	
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

int	execcmd(char **paths, char *argv, char **envp)
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