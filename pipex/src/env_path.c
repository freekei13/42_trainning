#include "pipex.h"

char	**paths_parse(char **env)
{
	int		i;
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

char	*find_full_path(char *cmd, char **env)
{
	int		i;
	char	*full_path;
	char	**paths;

	i = 0;
	if (!cmd)
		return (NULL);
	paths = paths_parse(env);
	while (paths[i])
	{
		full_path = full_path_parse(paths[i], cmd);
		ft_putendl_fd(full_path, 2);
		if (access(full_path, F_OK) == 0)
			return (free_all(paths), full_path);
		free(full_path);
		i++;
	}
	free_all(paths);
	return (NULL);
}
