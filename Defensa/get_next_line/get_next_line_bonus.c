/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 05:11:15 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/28 19:06:14 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_reminder(char *tmp)
{
	char	*rem;
	int		i;
	int		j;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (NULL);
	}
	rem = malloc(sizeof(char) * (ft_strlen(tmp) - i));
	if (!rem)
		return (NULL);
	i++;
	j = 0;
	while (tmp[i + j])
	{
		rem[j] = tmp[i + j];
		j++;
	}
	rem[j] = '\0';
	free(tmp);
	return (rem);
}

char	*get_new_line(char *tmp)
{
	char	*line;
	int		i;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_file(int fd, char *tmp)
{
	char		*buff;
	int			i;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (!ft_strchr(tmp) && i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (!tmp)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	tmp[fd] = read_file(fd, tmp[fd]);
	if (!tmp[fd])
	{
		tmp[fd] = NULL;
		return (0);
	}
	if (!(*tmp[fd]))
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	line = get_new_line(tmp[fd]);
	tmp[fd] = get_reminder(tmp[fd]);
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd1;
	int	fd2;
	char	*line1;
	char	*line2;

	if (argc != 3)
	{
		fprintf(stderr,
			"Uso: %s <archivo1> <archivo2>\n"
			"Demostración alternando lecturas con get_next_line_bonus.\n",
			argv[0]);
		return (EXIT_FAILURE);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		if (fd1 < 0)
			perror(argv[1]);
		if (fd2 < 0)
			perror(argv[2]);
		if (fd1 >= 0)
			close(fd1);
		if (fd2 >= 0)
			close(fd2);
		return (EXIT_FAILURE);
	}
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (!line1 && !line2)
			break ;
		if (line1)
		{
			printf("A: %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("B: %s", line2);
			free(line2);
		}
	}
	if (close(fd1) < 0)
		perror("close");
	if (close(fd2) < 0)
		perror("close");
	return (EXIT_SUCCESS);
}
