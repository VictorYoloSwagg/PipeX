/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:02:42 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/19 17:25:21 by vpramann         ###   ########.fr       */
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

#endif