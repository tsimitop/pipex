/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:00:41 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/29 20:48:05 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_failure(pid_t pid)
{
	if (pid == -1)
		handle_error("fork");
}

void	close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	handle_exit(int status)
{
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else
		status = EXIT_FAILURE;
	return (status);
}

void	handle_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	handle_error_free(char *str)
{
	perror(str);
	if (str)
		free(str);
	exit(EXIT_FAILURE);
}
