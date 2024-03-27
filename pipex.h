/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:09:13 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/27 20:15:24 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft.h"
// # include "ft_printf.h"
# include <fcntl.h>

void	handle_error(char *str);
int	child1_process(int *fd, char **argv, char **env);
void	child2_process(int *fd, char **argv, char **env);
void	parent_process(int *fd, char **argv, char **env);
char	*find_path(char *argv, char **env);
char	*iter_env(char *path, char *argv);
void	execute(char *cmd, char *argv, char **env);
char	*get_directory_name(char *argv);
// void	free_split(char **str);
// int		ft_printf(const char *str, ...);
void	proper_input(void);
void	failed_command(char *argv, int *fd);

#endif
