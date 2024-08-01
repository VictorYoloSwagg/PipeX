/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:02:42 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/01 18:19:00 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
#include <fcntl.h>

char	**ft_split(char const *s, char c);
int 	execcmd(char **paths, char *argv, char **envp);
char	**getpaths(char **envp);

#endif