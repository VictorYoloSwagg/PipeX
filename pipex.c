/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:11:23 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/09 19:52:49 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



int	main(int argc, char **argv, char **envp)
{
	int		fds[2];
	int		files[2];
	pid_t	pid;
	

	if (argc != 5)
		return 0;
	if (pipe(fds) < 0)
		exit (0);
	pid = fork();
	if (pid == -1)
		exit (0);
	if(pid == 0)
	{
		
		files[0] = open(argv[1], O_RDONLY, 0777);
		if (files[0] == -1)
			exit();
		dup2(fd[1], STDOUT_FILENO);
		dup2(files[0], STDIN_FILENO);
		close(fd[0]);
		execcmd(argv[2], envp);
	}
	waitpid(pid, NULL, 0);
	files[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (files[1] == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(files[1], STDOUT_FILENO);
	close(fd[1]);
	execcmd(argv[3], envp);
	return (0);
}
