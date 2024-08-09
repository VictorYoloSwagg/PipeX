/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpramann <vpramann@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:02:42 by vpramann          #+#    #+#             */
/*   Updated: 2024/08/01 18:58:32 by vpramann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
#include <fcntl.h>
# include "libft/libft.h"

int 	execcmd(char **paths, char *argv, char **envp);
char	**getpaths(char **envp);

#endif