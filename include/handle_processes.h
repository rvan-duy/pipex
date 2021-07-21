/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_processes.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/26 21:25:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/18 11:27:44 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_PROCESSES_H
# define HANDLE_PROCESSES_H

# include <sys/wait.h>

void	handle_processes(char **argv, int pipefds[2], char **envp);

#endif