/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_absolute_path_to_command.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 18:10:11 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/16 17:16:28 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "find_absolute_path_to_command.h"
#include "utilities.h"
#include "libft.h"

static char	**split_paths(char *path)
{
	char	**splitted_paths;

	splitted_paths = ft_split(path, ':');
	if (splitted_paths == NULL)
		error_and_exit("Failed to allocate memory.");
	free(path);
	return (splitted_paths);
}

static char	**add_command_to_paths(char **split_paths, const char *command)
{
	char	**combined_path;
	size_t	i;
	size_t	split_paths_len;

	split_paths_len = ft_array_len((void **)split_paths);
	combined_path = ft_calloc(split_paths_len + 1, sizeof(char *));
	if (combined_path == NULL)
		error_and_exit("Failed to allocate memory.");
	i = 0;
	while (split_paths[i])
	{
		combined_path[i] = ft_strjoin_three(split_paths[i], "/", command);
		if (combined_path[i] == NULL)
			error_and_exit("Failed to allocate memory.");
		i++;
	}
	ft_array_free((void **)split_paths, split_paths_len);
	return (combined_path);
}

static char	*find_valid_path(char **all_absolute_paths)
{
	size_t	i;
	char	*path;

	i = 0;
	path = NULL;
	while (all_absolute_paths[i])
	{
		if (access(all_absolute_paths[i], X_OK) > -1)
		{
			path = ft_strdup(all_absolute_paths[i]);
			if (path == NULL)
				error_and_exit("Failed to allocate memory.");
			break ;
		}
		i++;
	}
	ft_array_free((void **)all_absolute_paths, \
	ft_array_len((void **)all_absolute_paths));
	return (path);
}

char	*find_absolute_path_to_command(char *command, char **envp)
{
	char	*path_enviroment_variable;
	char	**all_possible_absolute_paths;
	char	**absolute_paths_with_command;
	char	*final_command;

	path_enviroment_variable = get_env_variable("PATH", envp);
	all_possible_absolute_paths = split_paths(path_enviroment_variable);
	absolute_paths_with_command = add_command_to_paths(\
	all_possible_absolute_paths, command);
	final_command = find_valid_path(absolute_paths_with_command);
	if (final_command == NULL)
	{
		ft_putstr_fd(command, 2);
		ft_putendl_fd(": command not found", 2);
		exit(EXIT_FAILURE);
	}
	return (final_command);
}
