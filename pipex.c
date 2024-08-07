/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:11:23 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/07 21:31:24 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**getpaths(char **envp)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (envp[j])
	{
		while(envp[j][i])
		{
			if (envp[j][i] == 'P' && envp[j][i + 1] == 'A' && envp[j][i + 2] == 'T' && envp[j][i + 3] == 'H' && envp[j][i + 4] == '=')
				return (ft_split(envp[j] + 5, ':'));
			i++;
		}
		j++;
	}
	return (NULL);
}

/*char	*findpath(char *paths)
{
	char	**path;

	path = ft_split(paths, ':');
	
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

int	main(int argc, char **argv, char **envp)
{
	/*char	**args;*/
	int		fds[2];
	pid_t	pid0;
	/*char **paths;*/
	/*pid_t	pid1;*/
	

	if (argc != 5)
		return 0;
	/*fds[0] = open(argv[1], O_RDONLY);
	fds[1] = open(argv[5], O_WRONLY);*/
	/*fds = getaccess(argv[1], argv[4]);*/
	if (!access(argv[1], F_OK))
		return(0);
	else
	{
		access(argv[1], R_OK);
		fds[0] = open(argv[1], O_RDONLY | O_APPEND, 0777);
	}	
	if (!access(argv[4], F_OK))
		open(argv[4], O_WRONLY | O_APPEND | O_CREAT, 0777);
	else
	{
		access(argv[4], W_OK);
		fds[1] = open(argv[4], O_WRONLY | O_APPEND, 0777);
	}
	if (pipe(fds) < 0)
		exit (1);
	if((pid0 = fork()) < 0)
	{
		exit (1);
	}
	else if((pid0 = fork()) == 0)
	{
		close(pid0);
		dup2(fds[0], STDIN_FILENO);
		execcmd(getpaths(envp), argv[2], envp);
	}
	else
	{
		close(pid0);
		dup2(fds[1], STDOUT_FILENO);
		execcmd(getpaths(envp), argv[3], envp);
	}
	/*
	open file 1
	trouver commande1
	open file 2
	trouver commande2
	creer pipe
	fork?
	child
		dup2
		fermer file1
		femer pipe0
		exec commande1
		
	parent
		dup2
		fermer pipe1
		exec commande 2
		
	fermer 
	*/
	return 0;
}
