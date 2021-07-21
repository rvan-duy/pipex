/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_command.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/26 21:07:18 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/18 12:14:36 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_COMMAND_H
# define EXECUTE_COMMAND_H

# define READ_PIPE 0
# define WRITE_PIPE 1
# define CHILD_PROCESS 0
# define IN_FILE 1
# define COMMAND_1 2
# define COMMNAD_2 3
# define OUT_FILE 4

# include <unistd.h>

void	execute_first_command(int pipefds[2], char **argv, char **envp);
void	execute_second_command(int pipefds[2], char **argv, char **envp);

#endif