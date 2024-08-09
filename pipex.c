/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:11:23 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/09 19:40:37 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



int	main(int argc, char **argv, char **envp)
{
	/*char	**args;*/
	int		fds[2];
	pid_t	pid;
	/*char **paths;*/
	/*pid_t	pid1;*/
	

	if (argc != 5)
		return 0;
	
	/*fds = getaccess(argv[1], argv[4]);*/
	// if (!access(argv[1], F_OK))
	// 	return(0);
	// else
	// {
	// 	access(argv[1], R_OK);
	// 	fds[0] = open(argv[1], O_RDONLY | O_APPEND, 0777);
	// }	
	// if (!access(argv[4], F_OK))
	// 	open(argv[4], O_WRONLY | O_APPEND | O_CREAT, 0777);
	// else
	// {
	// 	access(argv[4], W_OK);
	// 	fds[1] = open(argv[4], O_WRONLY | O_APPEND, 0777);
	// }
	if (pipe(fds) < 0)
		exit (0);
	pid = fork();
	if (pid == -1)
		exit (0);
	if(pid0 == 0)
	{
		fds[0] = open(argv[1], O_RDONLY , 0777);
		close(pid0);
		dup2(fds[0], STDIN_FILENO);
		execcmd(getpaths(envp), argv[2], envp);
	}
	else
	{
		fds[1] = open(argv[5], O_WRONLY | O_TRUNC | O_CREAT, 0777);
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
