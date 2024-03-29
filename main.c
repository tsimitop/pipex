/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:18:40 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/29 20:48:22 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	status = 0;
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			handle_error("pipe");
		pid = fork();
		fork_failure(pid);
		if (pid == 0)
			child1_process(fd, argv, env);
		pid = fork();
		fork_failure(pid);
		if (pid == 0)
			child2_process(fd, argv, env);
		close_fd(fd);
		waitpid(pid, &status, 0);
		status = handle_exit(status);
	}
	else
		proper_input();
	return (status);
}

void	proper_input(void)
{
	ft_printf("Acceptable input: ./pipex filein \"cmd1\" \"cmd2\" fileout\n");
	exit(EXIT_FAILURE);
}
