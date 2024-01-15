/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:31:29 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 12:51:27 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char *s, ...);

int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putnbr(int nb);
int			ft_putunbr(unsigned int nb);
int			ft_puthexlowernbr(unsigned int nb);
int			ft_puthexuppernbr(unsigned int nb);
int			ft_putptr(void *p, size_t i);

size_t		ft_countstr(const char *s);
size_t		ft_countdecnbr(int nb);
size_t		ft_countdecunbr(unsigned int nb);
size_t		ft_counthexnbr(unsigned int nb);
size_t		ft_countptrnbr(void *p);

int			ft_percent_put(const char *s, size_t i, size_t p);
size_t		ft_percent_count(const char *s, size_t i, size_t p);

char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);

#endif