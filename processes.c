/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:57:42 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/27 21:23:12 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child1_process(int *fd, char **argv, char **env)
{
	int		input_file;
	char	*cmd;
	char	*ret_str;

	close(fd[0]);
	input_file = open(argv[1], O_RDONLY, 0644); //bash does not create, text to open and werite
	if (input_file == -1 || access(argv[1], F_OK) == -1)
	{
		ret_str = ft_strjoin("pipex: ", argv[1]);
		if (!ret_str)
			return (0); // check leaks and exit value	
		handle_error(ret_str); // return proper value
	}
	if (access(argv[1], R_OK) == -1)
		handle_error("file is not readable"); // return proper value && you don't have permission to read / permission denied
	dup2(input_file, STDIN_FILENO);
	close(input_file);
	dup2(fd[1], STDOUT_FILENO);
	cmd = find_path(argv[2], env);
	if (!cmd)
		failed_command(argv[2], fd);
	execute(cmd, argv[2], env);
	close(fd[1]);
	perror("pipex"); //meh
	exit(EXIT_FAILURE);
}

void	failed_command(char *argv, int *fd)
{
	char	*ret_str;
	char	*small_cmd;

	small_cmd = get_directory_name(argv);
	if (!small_cmd)
		return ;
	ret_str = ft_strjoin("pipex: ", small_cmd);
	if (!ret_str)
		return ; // check leaks and exit value	
	ret_str = ft_strjoin(ret_str, ": command not found\n");
	write(2, ret_str, ft_strlen(ret_str));
	close(fd[1]);
	free(small_cmd);
	free(ret_str);
	exit(127);
}

void	child2_process(int *fd, char **argv, char **env)
{
	int		output_file;
	char	*cmd;

	close(fd[1]);
	output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file == -1 || access(argv[4], F_OK) == -1)
			handle_error("file does not exist"); // return proper value
	if (access(argv[4], W_OK) == -1)
		handle_error("file is not writable"); // return proper value && you don't have permission to write / permission denied
	dup2(output_file, STDOUT_FILENO);
	close(output_file);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	cmd = find_path(argv[3], env);
	if (!cmd)
		failed_command(argv[3], fd);
	execute(cmd, argv[3], env);
	perror("pipex");
	exit(EXIT_FAILURE);
}
