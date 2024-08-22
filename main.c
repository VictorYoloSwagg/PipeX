/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:11:23 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/20 22:11:41 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(char *file1, int *pipe_fds, char *cmd, char **envp)
{
	int	file;

	file = -1;
	if (access(file1, F_OK) == 0)
	{
		if (access(file1, F_OK & R_OK) == 0)
			file = open(file1, O_RDONLY, 0444);
		else
			print_errors(3, NULL, file1);
	}
	else
		print_errors(1, NULL, file1);
	if (file == -1)
		exit (1);
	dup2(file, STDIN_FILENO);
	dup2(pipe_fds[1], STDOUT_FILENO);
	close(pipe_fds[1]);
	close(pipe_fds[0]);
	close(file);
	exec_cmd(cmd, envp);
	exit(0);
}

static void	parent_process(char *file2, int *pipe_fds, char *cmd, char **envp)
{
	int	file;

	file = -1;
	if (find_cmd_path(cmd, envp) != NULL)
		file = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0622);
	if (file == -1)
		exit(1);
	dup2(pipe_fds[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(pipe_fds[1]);
	close(pipe_fds[0]);
	close(file);
	exec_cmd(cmd, envp);
	exit(0);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fds[2];
	pid_t	pid;

	if (argc != 5)
	{
		print_errors(2, NULL, NULL);
		return (1);
	}
	if (pipe(pipe_fds) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		child_process(argv[1], pipe_fds, argv[2], envp);
	else
	{
		wait(0);
		parent_process(argv[4], pipe_fds, argv[3], envp);
	}
	return (0);
}
