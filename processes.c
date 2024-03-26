/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:57:42 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/26 21:09:53 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child1_process(int *fd, char **argv, char **env)
{
	int		input_file;
	char	*cmd;

// close read pipe
	close(fd[0]);
	input_file = open(argv[1], O_RDONLY, 0644); //bash does not create, text to open and werite
	if (input_file == -1)
		handle_error("input_file");
		// does file exist (access) X_OK F_OK(means file exists) R_OK
	dup2(input_file, STDIN_FILENO);
	close(input_file);
	dup2(fd[1], STDOUT_FILENO);
	// close write
	cmd = find_path(argv[2], env);
	if (!cmd)
	{
		// dup2(STDOUT_FILENO, stdoutput);
		// ft_putstr_fd("pipex: ", stdout);
		// return_er = argv[3];
		// ft_putstr_fd(return_er, stdout);
		// ft_putstr_fd(": command not found", stdout);
			// write(1, "hi\n", 3);

		// ft_printf("pipex: %s: command not found", argv[3]);
		// cmd = ft_strjoin("pipex: ", get_directory_name(argv[3]));
		// cmd = (cmd, ": command not found");
		// handle_error("pipex: cmd1");
	close(fd[1]);
	return (127);
	}
	execute(cmd, argv[2], env);
	close(fd[1]);
	perror("pipex");
	return (0);
}

void	child2_process(int *fd, char **argv, char **env)
{
	int		output_file;
	char	*cmd;
	// char	*return_er;

	close(fd[1]);
	output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file == -1)
		handle_error("output_file");
	dup2(output_file, STDOUT_FILENO);
	close(output_file);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	cmd = find_path(argv[3], env);
	if (!cmd)
	{
		// ft_printf("pipex: %s: command not found", argv[3]);
		// return_er = ft_strjoin("pipex: ", get_directory_name(argv[3]));
		// return_er = (return_er, ": command not found");
		// handle_error("yooooooooooo");
		exit (127);
	}
	execute(cmd, argv[3], env);
	perror("pipex");
	exit(EXIT_FAILURE);
}
