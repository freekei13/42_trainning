#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd_in;
	int		fd_out;
	int		pipefds[2];
	pid_t	pid;

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
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])) != NULL)
			break ;
		i++;
	}
	ft_printf("%d\n", i);
	char *path_s = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	char **paths = ft_split(path_s, ':');
	free(path_s);
	i = 0;
	while (paths[i])
	{
		ft_printf("%s\n", paths[i]);
		i++;
	}
}