/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:16:13 by csamakka          #+#    #+#             */
/*   Updated: 2025/12/16 21:24:12 by csamakka         ###   ########.fr       */
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

void	parent_role(int n_cmd, int i, int *fd, int *pipefd)
{
	if (i != n_cmd - 1)
		{
			close(*fd);
			close(pipefd[1]);
			*fd = pipefd[0];
		}
		else
			close(*fd);
}

void	pipex_loop(char **av, char **env, t_data data)
{
	pid_t	n_pid;
	int		pipefd[2];
	int		prev_fd;
	int		i;
	
	prev_fd = data.fd_in;
	i = 0;
	while (i < data.n_cmd)
	{
		if (i == data.n_cmd - 1)
		{
			n_pid = fork();
			if (n_pid == 0)
				l_child(av[data.start_cmd + i], env, data.fd_out, prev_fd);
		}
		else
		{
			pipe(pipefd);
			n_pid = fork();
			if (n_pid == 0)
				n_child(av[data.start_cmd + i], env, prev_fd, pipefd);
		}
		parent_role(data.n_cmd, i, &prev_fd, pipefd);
		i++;
	}
}

void	here_doc(char **av, int *fd_in)
{
	pid_t	pid;
	int		pipefd[2];
	char	*input;
	
	if (pipe(pipefd) == -1)
	{
		perror("here_doc");
		exit(0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("here_doc");
		exit(0);
	}
	if (pid == 0)
	{
		close(pipefd[0]);
		while (1)
		{
			input = get_next_line(0);
			if (ft_strncmp(av[2], input, ft_strlen(input) - 1) == 0)
			{
				free(input);
				exit(0);
			}
			ft_putstr_fd(input, pipefd[1]);
			free(input);
		}
	}
	close(pipefd[1]);
	*fd_in = pipefd[0];
	dup2(*fd_in, 0);
	wait(NULL);
}

void	pipex(int ac, char **av, char **env)
{
	t_data	data;

	if (ac < 5)
	{
		ft_putstr_fd("file1 cmd1 cmd2 cmdn file2\n", 2);
		exit(0);
	}
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		if (ac < 6)
		{
			ft_putstr_fd("here_doc LIMITER cmd1 cmd2 cmdn file", 2);
			exit(0);
		}
		here_doc(av, &data.fd_in);
		data.n_cmd = ac - 4;
	}
	else
	{
		data.n_cmd = ac - 3;
		data.fd_in = open_file(av[1], 0);
	}
	data.start_cmd = ac - data.n_cmd - 1;
	data.fd_out = open_file(av[ac - 1], 1);
	pipex_loop(av, env, data);
	close(data.fd_in);
	close(data.fd_out);
	while (data.n_cmd > 0)
	{
		wait(&data.status);
		data.n_cmd--;
	}
}

int	main(int argc, char **argv, char **env)
{
	pipex(argc, argv, env);
	return (0);
}
