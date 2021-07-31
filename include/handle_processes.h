/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_processes.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/26 21:25:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/31 16:58:00 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_PROCESSES_H
# define HANDLE_PROCESSES_H

# include <sys/wait.h>

void	handle_processes(char **argv, int pipefds[2], char **envp);

#endif