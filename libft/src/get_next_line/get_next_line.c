/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:39:53 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 13:39:53 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

void	ft_clear_stash(char **stash)
{
	if (*stash)
		free(*stash);
	*stash = NULL;
	return ;
}

void	ft_update_stash(char **stash, char **buffer)
{
	char	*temp_stash;

	temp_stash = ft_strjoin(*stash, *buffer);
	free(*stash);
	*stash = temp_stash;
}

char	*ft_check_last(char **stash, char **buffer)
{
	char	*line;

	if (!*stash)
		return (free(*buffer), NULL);
	else if (*stash[0] == 0)
		return (free(*buffer), ft_clear_stash(&*stash), NULL);
	line = ft_strndup(*stash, 0, ft_strlen(*stash));
	ft_clear_stash(&*stash);
	return (free(*buffer), line);
}

char	*ft_get_line(char **stash)
{
	char	*line;
	char	*temp_stash;

	line = ft_strndup(*stash, 0, ft_findnline(*stash));
	temp_stash = ft_strndup(*stash, ft_findnline(*stash), ft_strlen(*stash));
	free(*stash);
	*stash = temp_stash;
	if (!*stash || !line)
		return (ft_clear_stash(&*stash), free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*buffer;
	int			readc;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (ft_clear_all_stash(stash), NULL);
	while (ft_findnline(stash[fd]) == -1)
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
			return (ft_clear_stash(&stash[fd]), NULL);
		readc = read(fd, buffer, BUFFER_SIZE);
		if (readc <= 0)
			return (ft_check_last(&stash[fd], &buffer));
		else if (stash[fd])
			ft_update_stash(&stash[fd], &buffer);
		else
			stash[fd] = ft_strndup(buffer, 0, ft_strlen(buffer));
		free(buffer);
	}
	return (ft_get_line(&stash[fd]));
}
