/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:11:23 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/13 19:17:34 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
static void	child_process(char 	*file1, int *fds,char *cmd, char **envp)
{
	int file;
	
	file = open(file1, O_RDONLY, 0777);
	if (file == -1)
		exit(0);
	dup2(fds[0], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(fds[1]);
	exec(cmd, envp);
}

static void	parent_process(char *file2, int *fds, char *cmd, pid_t pid, char **envp)
{
	int file;

	waitpid(pid, NULL, 0);
	file = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		exit(0);
	dup2(fds[1], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fds[0]);
	exec(cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fds[2];
	pid_t	pid;
	
	if (argc != 5)
		return 0;
	if (pipe(fds) < 0)
		exit (0);
	pid = fork();
	if (pid == -1)
		exit (0);
	if(pid == 0)
		child_process(argv[1], fds, argv[2], envp);
	parent_process(argv[4], fds, argv[3], pid, envp);
	return (0);
}
