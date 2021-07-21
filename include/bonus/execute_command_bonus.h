/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_command_bonus.h                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/18 17:44:55 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/18 22:36:33 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_COMMAND_BONUS_H
# define EXECUTE_COMMAND_BONUS_H

# define READ_PIPE 0
# define WRITE_PIPE 1
# define CHILD_PROCESS 0
# define IN_FILE 1
# define COMMAND_1 2
# define COMMNAD_2 3
# define OUT_FILE 4

# include <unistd.h>
# include <sys/wait.h>

void	execute_first_command(int **pipefds, char **argv, char **envp);
void	execute_final_command(int pipefds[2], char **argv, char **envp);
void	execute_middle_command(int pipefds[2], char *argv, char **envp);
void	execute_next_command(int read_pipe, int write_pipe, \
								char *argv, char **envp);

#endif