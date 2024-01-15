/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:47:21 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/23 17:47:21 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

char	*ft_get_line(char **stash);
char	*ft_check_last(char **stash, char **buffer);
void	ft_update_stash(char **stash, char **buffer);
void	ft_clear_stash(char **stash);
void	ft_clear_all_stash(char **stash);

long	ft_findnline(const char *s);
char	*ft_strndup(char *src, size_t start, size_t end);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

#endif
