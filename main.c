/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:18:40 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/28 19:28:30 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void print_args(char **argv);

int	main(int argc, char **argv, char **env)
{

	int		fd[2];
	pid_t	pid;
	int		status;
// print_args(argv);
	status = 0;
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			handle_error("pipe");
		pid = fork();
		if (pid == -1)
			handle_error("fork");
		if (pid == 0)
			child1_process(fd, argv, env);
		pid = fork();
		if (pid == -1)
			handle_error("fork");
		if (pid == 0)
			child2_process(fd, argv, env);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, &status, 0); //check
		if (WIFEXITED(status)) //WIFEXITED(status) : returns true if the child terminated normally.
		{
			status = WEXITSTATUS(status);//WEXITSTATUS(status) : returns the exit status of the child. This macro should be employed only if WIFEXITED returned true.
			// printf("WIFEXITED status = %i\n", status);
		}
		else
		{
			// printf("1 else status = %i\n", status);
			status = EXIT_FAILURE;// Maybe set an appropriate error code// Handle if the child process did not exit normally
			// printf("2 else status = %i\n", status);
		}
	}
	else
		proper_input();
	return (status);
}

void	proper_input(void)
{
	printf("Acceptable input: ./pipex filein \"cmd1\" \"cmd2\" fileout\n");
	exit(EXIT_FAILURE);
}

void	handle_error(char *str)
{
	perror(str);
	// if (str)
	// 	free(str);
	exit(127);
}

//dorker valgrind --leak-check=full --trace-children=yes ./pipex in.txt "ls -lah" "grep a" out
//dorker valgrind --leak-check=full --trace-children=yes --show-leak-kinds=all -s
//--track-fds=yes
//-----valgrind --leak-check=full --trace-children=yes --track-origins=yes -s ./pipex in.txt "grep hi" "grep hello" out
// dorker valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all -s ./pipex in.txt \"grep hi\" \"grep hello\" out
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

void print_args(char **argv)
{
	int i = 0;

	while(argv[i])
	{
		printf("argv[%i] = %s\n", i, argv[i]);
		i++;
	}
}
