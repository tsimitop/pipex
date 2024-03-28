/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:54:35 by tsimitop          #+#    #+#             */
/*   Updated: 2024/03/28 19:51:52 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *argv, char **env)
{
	char	*path;
	char	*cmd;
	int		i;

	i = 0;
	path = "PATH=";
	while (env[i] && ft_strncmp(env[i], path, 5) != 0)
		i++;
	path = env[i];
	cmd = iter_env(path, argv);
	return (cmd);
}

char	*get_directory_name(char *argv)
{
	int		i;
	char	*small_cmd;

	i = 0;
	while (argv[i] != '\0' && argv[i] != ' ')
		i++;
	small_cmd = ft_calloc(i + 1, sizeof(char));
	if (!small_cmd)
		return (NULL); //check for ret values and leaks
	i = 0;
	while (argv[i] != '\0' && argv[i] != ' ')
	{
		small_cmd[i] = argv[i];
		// write(2, &small_cmd[i], 1);
		// write(2, "\n", 1);
		i++;
	}
	return (small_cmd);
}

char	*iter_env(char *path, char *argv)
{
	int		i;
	char	**env_split;
	char	*cmd;
	char	*str;
	char	*small_cmd;
	char	*ret_str;

	str = "/";
	i = 0;
	small_cmd = get_directory_name(argv);
	if (!small_cmd)
	{
		ret_str = ft_strjoin("pipex: ", argv);
		if (!ret_str)
			return (NULL); // check leaks and exit value	
		handle_error(ret_str); // return proper value
		// handle_error("command not found")
	}
	argv = ft_strjoin(str, small_cmd);
	env_split = ft_split(path + 5, ':');
	while (env_split[i])
	{
		cmd = ft_strjoin(env_split[i], argv);
		if (access(cmd, X_OK) != -1)
			return (free_split(env_split), free(small_cmd), cmd);
		i++;
	}
	return (free_split(env_split), free(small_cmd), NULL);
}

void	execute(char *cmd, char *argv, char **env)
{
	execve(cmd, ft_split(argv, ' '), env);
	handle_error("execve");
}
