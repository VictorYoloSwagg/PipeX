/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:11:23 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/20 21:29:15 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(char *file1, int *pipe_fds, char *cmd, char **envp)
{
	int	file;

	file = -1;
	if (access(file1, F_OK) == 0)
		file = open(file1, O_RDONLY, 0777);
	else
		print_errors(1, NULL, file1);
	if (file == -1)
		return ;
	dup2(file, STDIN_FILENO);
	dup2(pipe_fds[1], STDOUT_FILENO);
	close(pipe_fds[1]);
	close(pipe_fds[0]);
	close(file);
	exec_cmd(cmd, envp);
}

static void	parent_process(char *file2, int *pipe_fds, char *cmd, char **envp)
{
	int	file;

	file = -1;
	if (find_cmd_path(cmd, envp) != NULL)
		file = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		exit(0);
	dup2(pipe_fds[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(pipe_fds[1]);
	close(pipe_fds[0]);
	close(file);
	exec_cmd(cmd, envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fds[2];
	pid_t	pid;

	if (argc != 5)
		return (0);
	if (pipe(pipe_fds) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
		child_process(argv[1], pipe_fds, argv[2], envp);
	else
	{
		waitpid(pid, NULL, 0);
		parent_process(argv[4], pipe_fds, argv[3], envp);
	}
	system ("leaks pipex");
	return (1);
}
