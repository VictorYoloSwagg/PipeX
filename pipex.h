/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:02:42 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/10 16:24:09 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

/*int 	execcmd(char **paths, char *argv, char **envp);*/
void	free_tab(char **tab);
char	**getpaths(char **envp);
void	exec(char *cmd, char **envp);
char	*findpath(char *cmd, char **envp);

#endif