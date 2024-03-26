/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:18:40 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/26 21:43:16 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;
	char *str;

	status = 0;
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			handle_error("pipe");
		pid = fork();
		if (pid == -1)
			handle_error("fork");
		if (pid == 0)
		{
			status = child1_process(fd, argv, env);
			str = ft_itoa(status);
		write(2, "h1\n", 3);
		write(2, str, ft_strlen(str));
			exit(status);
		}
		str = ft_itoa(status);
		write(2, "h2\n", 3);
		write(2, str, ft_strlen(str));

		// pid = fork();
		// if (pid == 0)
		// 	child2_process(fd, argv, env);
		child2_process(fd, argv, env);
		close(fd[0]);
		close(fd[1]);
		// wait(NULL);
		waitpid(pid, &status, 0);
		str = ft_itoa(status);
		write(2, "h3\n", 3);
		write(2, str, ft_strlen(str));

		// WIFEXITED(status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);// Get the exit status of the child process
		else
			status = EXIT_FAILURE;// Maybe set an appropriate error code// Handle if the child process did not exit normally
	}
	else
		status = EXIT_FAILURE;// Handle incorrect command line arguments
	return status;	// Return the status from the main function
}

void	handle_error(char *str)
{
	// (void)str;
	perror(str);
	exit(127);
}

//dorker valgrind --leak-check=full --trace-children=yes 
//  ./pipex file1.txt "ls -lah" "grep a" fileout.txt
/*
echo $?

checks || return values and messages
< in.txt grep hi | Libft/ out
< in.txt grep hi | Libft out
< in.txt grepp | grepp out 

./pipex in.txt "grepp hi" "grepp" out
path not found: No such file or directory
< in.txt grepp hi | grepp out
bash: grepp: command not found
bash: grepp: command not found
*/
