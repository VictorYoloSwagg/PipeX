/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:11:23 by vpramann          #+#    #+#             */
/*   Updated: 2024/07/31 22:03:47 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath(char **envp)
{
	int	i;
	int	j;
	
	
}

int	main(int argc, char **argv, char **envp)
{
	char	**args;
	int		fds[2];
	pid_t	pid0;
	/*pid_t	pid1;*/
	

	if (argc != 5)
		return 0;
	fds[0] = open(argc[1], O_RDONLY);
	fds[1] = open(argc[5], O_WRONLY);
	if (pipe(fds) < 0)
		exit (1);
	if((pid0 = fork()) < 0)
	{
		exit (1);
	}
	if((pid0 = fork()) > 0);
	{
		close(pid0);
		dup2(fds[0], STDIN_FILENO);
		execve(/*pathname*/, argv[2], envp);
	}
	else
	{
		close(pid0);
		dup2(fds[1], STDOUT_FILENO);
		execve(/*pathname*/, argv[3], envp);
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
