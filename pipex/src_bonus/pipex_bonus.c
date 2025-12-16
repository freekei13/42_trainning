/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:16:13 by csamakka          #+#    #+#             */
/*   Updated: 2025/12/16 01:42:32 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_cmd(char *arg, char *cmd_path, char **cmd, char **env)
{
	if (!cmd_path)
	{
		ft_putstr_fd(cmd[0], 2);
		ft_putendl_fd(": command not found", 2);
		free_all(cmd);
		exit(127);
	}
	if (execve(cmd_path, cmd, env) == -1)
	{
		perror(arg);
		free_all(cmd);
		free(cmd_path);
		exit(126);
	}
}

void	n_child(char *av, char **env, int fd, int *pipefd)
{
	char	**cmd;
	char	*cmd_path;
	
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	close(pipefd[1]);
	cmd = ft_split(av, ' ');
	cmd_path = find_full_path(cmd[0], env);
	exec_cmd(av, cmd_path, cmd, env);
}

void	l_child(char *av, char **env, int fd, int prev_fd)
{
	char	**cmd;
	char	*cmd_path;
	
	dup2(fd, 1);
	dup2(prev_fd, 0);
	close(fd);
	close(prev_fd);
	cmd = ft_split(av, ' ');
	cmd_path = find_full_path(cmd[0], env);
	exec_cmd(av, cmd_path, cmd, env);
}

void	pipex(int ac, char **av, char **env)
{
	pid_t	n_pid;
	int		pipefd[2];
	int		status;
	int		n_cmd;
	int		start_cmd;
	int		fd_in;
	int		fd_out;
	int		prev_fd;
	int		i;

	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
		n_cmd = ac - 4;
	else
		n_cmd = ac - 3;
	start_cmd = ac - n_cmd - 1;
	fd_in = open_file(av[1], 0);
	fd_out = open_file(av[ac - 1], 1);
	prev_fd = fd_in;
	i = 0;
	while (i < n_cmd)
	{
		if (i == n_cmd - 1)
		{
			n_pid = fork();
			if (n_pid == 0)
				l_child(av[start_cmd + i], env, fd_out, prev_fd);
		}
		else
		{
			pipe(pipefd);
			n_pid = fork();
			if (n_pid == 0)
				n_child(av[start_cmd + i], env, prev_fd, pipefd);
		}
		if (i != n_cmd - 1)
		{
			close(prev_fd);
			close(pipefd[1]);
			prev_fd = pipefd[0];
		}
		else
			close(prev_fd);
		i++;
	}
	close(fd_in);
	close(fd_out);
	while (n_cmd > 0)
	{
		wait(&status);
		n_cmd--;
	}
}

int	main(int argc, char **argv, char **env)
{
	pipex(argc, argv, env);
	return (0);
}
