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
	int		pipefds[2];
	pid_t	pid;
	char	**paths;
	char	**args;

	if (argc < 5 || argc > 5)
		return (0);

	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
		perror("infile");
	if (access(argv[4], F_OK) == -1 || access(argv[4], W_OK) == -1)
		perror("outfile");
	fd_in = open(argv[1], O_RDONLY);
	if (pipe(pipefds) == -1)
		perror("ERROR");
	int i = 0;
	paths = paths_parse(envp);
	args = ft_split(argv[2], ' ');
	char *cmd_path = find_full_path(paths, args[0]);
	ft_printf("%s\n", cmd_path);
}
