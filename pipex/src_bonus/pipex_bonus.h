/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:15:58 by csamakka          #+#    #+#             */
/*   Updated: 2025/12/17 18:21:13 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <sys/wait.h> 
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

typedef struct s_data
{
	int	fd_in;
	int	fd_out;
	int	prev_fd;
	int	n_cmd;
	int	start_cmd;
	int	status;
}		t_data;

char	*find_full_path(char *cmd, char **env);
int		open_file(char *path, int in_out);
int		ft_tablen(char **strs);

#endif