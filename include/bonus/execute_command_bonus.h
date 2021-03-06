/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_command_bonus.h                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/18 17:44:55 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/21 15:44:02 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_COMMAND_BONUS_H
# define EXECUTE_COMMAND_BONUS_H

# define READ_PIPE 0
# define WRITE_PIPE 1
# define CHILD_PROCESS 0

# include "structs_bonus.h"
# include <unistd.h>
# include <sys/wait.h>

void	execute_next_command(int read_pipe, int write_pipe, \
								char *argv, char **envp);

#endif