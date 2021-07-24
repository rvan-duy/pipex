/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_heredoc_bonus.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/23 10:18:24 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/24 11:05:37 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_HEREDOC_BONUS_H
# define HANDLE_HEREDOC_BONUS_H

# include "structs_bonus.h"
# include <stdbool.h>

void	handle_heredoc(t_command_line_arguments *arg, int **pipefds);

#endif