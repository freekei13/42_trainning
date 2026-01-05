/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamakka <csamakka@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:16:13 by csamakka          #+#    #+#             */
/*   Updated: 2026/01/05 15:55:53 by csamakka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_cmd(char *arg, char *cmd_path, char **cmd, char **env)
{
	if (!cmd_path)
	{
		if (cmd[0] == NULL)
			ft_putstr_fd("", 2);
		else
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

void	n_child(char *av, char **env, t_data *data, int *pipefd)
{
	char	**cmd;
	char	*cmd_path;

	dup2(data->prev_fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	close(pipefd[1]);
	close(data->prev_fd);
	close(data->fd_out);
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

void	parent_role(t_data *data, int i, int *pipefd)
{
	if (i != data->n_cmd - 1)
	{
		close(data->prev_fd);
		close(pipefd[1]);
		data->prev_fd = pipefd[0];
	}
}

void	l_child_role(pid_t pid, t_data *data, char **av, char **env)
{
	pid = fork();
	if (pid == -1)
		print_error_exit("n_pid");
	if (pid == 0)
		l_child(av[data->start_cmd + data->n_cmd - 1],
			env, data->fd_out, data->prev_fd);
}

void	pipex_loop(char **av, char **env, t_data *data)
{
	pid_t	n_pid;
	int		pipefd[2];
	int		i;

	data->prev_fd = data->fd_in;
	i = 0;
	while (i < data->n_cmd)
	{
		if (i == data->n_cmd - 1)
			l_child_role(n_pid, data, av, env);
		else
		{
			if (pipe(pipefd) == -1)
				print_error_exit("pipe");
			n_pid = fork();
			if (n_pid == -1)
				print_error_exit("n_pid");
			if (n_pid == 0)
				n_child(av[data->start_cmd + i], env, data, pipefd);
		}
		parent_role(data, i, pipefd);
		i++;
	}
}

void	here_doc_loop(char **av, int *pipefd)
{
	char	*input;

	close(pipefd[0]);
	while (1)
	{
		input = get_next_line(0);
		if (ft_strncmp(av[2], input, ft_strlen(av[2])) == 0
			&& ft_strlen(av[2]) == ft_strlen(input) - 1)
		{
			free(input);
			close(pipefd[1]);
			//get_next_line(-1);
			exit(0);
		}
		ft_putstr_fd(input, pipefd[1]);
		free(input);
	}
}

void	here_doc(char **av, int *fd_in)
{
	pid_t	pid;
	int		pipefd[2];

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
		here_doc_loop(av, pipefd);
	close(pipefd[1]);
	*fd_in = pipefd[0];
	wait(NULL);
}

void	set_start(int ac, char **av, t_data *data)
{
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
		here_doc(av, &(*data).fd_in);
		data->n_cmd = ac - 4;
	}
	else
	{
		data->n_cmd = ac - 3;
		data->fd_in = open_file(av[1], 0);
	}
}

void	pipex(int ac, char **av, char **env)
{
	t_data	data;

	set_start(ac, av, &data);
	data.start_cmd = ac - data.n_cmd - 1;
	data.fd_out = open_file(av[ac - 1], 1);
	pipex_loop(av, env, &data);
	close(data.fd_out);
	if (data.fd_in != data.prev_fd)
		close(data.fd_in);
	close(data.prev_fd);
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
