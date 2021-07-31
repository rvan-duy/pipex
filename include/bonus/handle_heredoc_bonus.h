/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_heredoc_bonus.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-duy <rvan-duy@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/23 10:18:24 by rvan-duy      #+#    #+#                 */
/*   Updated: 2021/07/31 15:29:21 by rvan-duy      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_HEREDOC_BONUS_H
# define HANDLE_HEREDOC_BONUS_H

# include "structs_bonus.h"

# define TMP_FILE 0
# define OUT_FILE 1

void	handle_heredoc(t_command_line_arguments *arg, int **pipefds);

#endif