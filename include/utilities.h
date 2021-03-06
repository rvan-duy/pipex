/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/23 13:23:21 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/21 09:22:45 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

void	error_and_exit(char *message);
pid_t	fork_process(void);
void	close_fd(int fd);
int		open_file_with_read_permissions(char *argv);
int		open_file_with_write_permissions(char *argv);
char	**combine_command(char *absolute_path, char **arguments);
char	*get_env_variable(char *variable, char **env_variables);
void	dup_fd(int fd1, int fd2);

#endif