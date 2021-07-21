/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_and_error_check_command.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 17:59:01 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/16 17:15:54 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "find_absolute_path_to_command.h"
#include "utilities.h"
#include "libft.h"

static char	*get_absolute_command(char *command, char **envp)
{
	char	*pwd;
	char	*absolute_command;

	if (command == NULL)
	{
		ft_putendl_fd(": command not found", 2);
		exit(EXIT_FAILURE);
	}
	if (command[0] == '/')
		return (ft_strdup(command));
	if (ft_strchr(command, '/'))
	{
		pwd = get_env_variable("PWD", envp);
		absolute_command = ft_strjoin_three(pwd, "/", command);
		free(pwd);
		return (absolute_command);
	}
	return (find_absolute_path_to_command(command, envp));
}

char	**read_and_error_check_command(char *argument, char **envp)
{
	char	**splitted_command_and_arguments;
	char	*command;
	char	*absolute_command;
	char	**final_command_with_arguments;

	splitted_command_and_arguments = ft_split(argument, ' ');
	if (splitted_command_and_arguments == NULL)
		error_and_exit("Failed to allocate memory.");
	command = splitted_command_and_arguments[0];
	absolute_command = get_absolute_command(command, envp);
	if (absolute_command == NULL)
		error_and_exit("Failed to allocate memory.");
	if (access(absolute_command, X_OK) < 0)
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		free(absolute_command);
	}
	final_command_with_arguments = combine_command(absolute_command, \
	splitted_command_and_arguments + 1);
	ft_array_free((void **)splitted_command_and_arguments, \
	ft_array_len((void **)splitted_command_and_arguments));
	return (final_command_with_arguments);
}
