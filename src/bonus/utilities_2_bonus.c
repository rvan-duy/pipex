/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities_2_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/26 21:38:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/21 12:47:21 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utilities_bonus.h"
#include "libft.h"

char	**combine_command(char *absolute_path, char **arguments)
{
	char	**combined_command;
	size_t	array_len;
	size_t	i;

	if (absolute_path == NULL)
		return (NULL);
	array_len = 1 + ft_array_len((void **)arguments);
	combined_command = ft_calloc(array_len + 1, sizeof(char *));
	if (combined_command == NULL)
		error_and_exit("Failed to allocate memory.");
	combined_command[0] = ft_strdup(absolute_path);
	if (combined_command[0] == NULL)
		error_and_exit("Failed to allocate memory.");
	free(absolute_path);
	i = 1;
	while (i < array_len)
	{
		combined_command[i] = ft_strdup(arguments[i - 1]);
		if (combined_command[i] == NULL)
			error_and_exit("Failed to allocate memory.");
		i++;
	}
	return (combined_command);
}

char	*get_env_variable(char *variable, char **env_variables)
{
	const size_t	len = ft_strlen(variable) + 1;
	char			*paths;
	char			*combined_string;
	size_t			i;

	i = 0;
	combined_string = ft_strjoin(variable, "=");
	if (combined_string == NULL)
		error_and_exit("Failed to allocate memory.");
	while (env_variables[i])
	{
		if (ft_strncmp(combined_string, env_variables[i], len) == 0)
		{
			paths = ft_strdup(env_variables[i] + len);
			if (paths == NULL)
				error_and_exit("Failed to allocate memory.");
			free(combined_string);
			return (paths);
		}
		i++;
	}
	error_and_exit("Failed to find environment variable");
	return (NULL);
}

void	dup_fd(int fd1, int fd2)
{
	if (dup2(fd1, fd2) < 0)
	{
		ft_putendl_fd("Error", 2);
		perror("dup2");
		exit(EXIT_FAILURE);
	}
}

#include <stdio.h>

void	close_other_fds(int **pipefds, int fd1, int fd2)
{
	int	i;
	int	j;

	i = 0;
	while (pipefds[i] != NULL)
	{
		j = 0;
		while (j < 2)
		{
			if (pipefds[i][j] != fd1 && pipefds[i][j] != fd2)
				close(pipefds[i][j]);
			j++;
		}
		i++;
	}
}

void	close_all_fds(int **pipefds)
{
	int	i;
	int	j;

	i = 0;
	while (pipefds[i] != NULL)
	{
		j = 0;
		while (j < 2)
		{
			close(pipefds[i][j]);
			j++;
		}
		i++;
	}
}
