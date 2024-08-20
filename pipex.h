/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:02:42 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/20 21:39:37 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	free_tab(char **tab);
char	*get_paths(char **envp);
void	exec_cmd(char *cmd, char **envp);
char	*find_cmd_path(char *cmd, char **envp);
void	print_errors(int i, char **cmds, char *file1);
void	free_tabs(char **tab1, char **tab2);
void	free_strs(char *str1, char *str2);
void	print_errors(int i, char **cmds, char *file1);
char	*find_path(char **paths, char **cmds, int i);

#endif