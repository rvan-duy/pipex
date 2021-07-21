/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_command_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/18 17:35:56 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/21 15:44:34 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "execute_command_bonus.h"
#include "read_and_error_check_command.h"
#include "utilities.h"

void	execute_next_command(int read_pipe, int write_pipe, \
								char *argv, char **envp)
{
	char	**command;

	command = read_and_error_check_command(argv, envp);
	dup_fd(read_pipe, STDIN_FILENO);
	close_fd(read_pipe);
	dup_fd(write_pipe, STDOUT_FILENO);
	close_fd(write_pipe);
	execve(command[0], (char *const *)command, envp);
}
