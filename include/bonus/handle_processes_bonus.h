/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_processes_bonus.h                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/26 21:25:20 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/21 12:21:19 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_PROCESSES_BONUS_H
# define HANDLE_PROCESSES_BONUS_H

# include <sys/wait.h>

# define FIRST_COMMAND 0

void	handle_processes(int argc, char **argv, int **pipefds, char **envp);

#endif