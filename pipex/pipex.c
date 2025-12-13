#include "pipex.h"

char	**paths_parse(char **env)
{
	int	i;
	char	*path_s;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", ft_strlen(env[i])) != NULL)
			break ;
		i++;
	}
	path_s = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
	paths = ft_split(path_s, ':');
	free(path_s);
	return (paths);
}

char	*full_path_parse(char *path, char *cmd)
{
	int		size;
	char	*full_path;
	char	*tmp;

	size = ft_strlen(path);
	if (path[size - 1] == '/')
	{
		full_path = ft_strjoin(path, cmd);
		return (full_path);
	}
	tmp = ft_strjoin(path, "/");
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full_path);
}

char	*find_full_path(char **paths, char *cmd)
{
	int		i;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		full_path = full_path_parse(paths[i], cmd);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_in;
	int		fd_out;
	int		pipefd1[2];
	pid_t	pid;
	char	**paths;
	char	**args1;
	char	**args2;
	pid_t	pid1;
	pid_t	pid2;

	if (argc < 5 || argc > 5)
		return (0);
	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
		perror("infile");
	if (access(argv[4], F_OK) == -1 || access(argv[4], W_OK) == -1)
		perror("outfile");
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4], O_WRONLY);
	if (pipe(pipefd1) == -1)
		perror("ERROR");
	paths = paths_parse(envp);
	args1 = ft_split(argv[2], ' ');
	args2 = ft_split(argv[3], ' ');
	pid1 = fork();
	char *cmd_path1 = find_full_path(paths, args1[0]);
	char *cmd_path2 = find_full_path(paths, args2[0]);
	if (cmd_path1 == NULL || cmd_path2 == NULL)
		perror("ERROR");
	if (pid1 == 0)
	{
		dup2(fd_in, 0);
		dup2(pipefd1[1], 1);
		close(fd_out);
		close(pipefd1[0]);
		close(fd_in);
		close(pipefd1[1]);
		execve(cmd_path1, args1, envp);
		exit(1);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(pipefd1[0], 0);
		dup2(fd_out, 1);
		close(fd_in);
		close(pipefd1[1]);
		close(fd_out);
		close(pipefd1[0]);
		execve(cmd_path2, args2, envp);
		exit(1);
	}
	close(fd_in);
	close(fd_out);
	close(pipefd1[0]);
	close(pipefd1[1]);
	int status;
	waitpid(P_ALL, &status, 0);
}
