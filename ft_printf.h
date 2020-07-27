/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:49:14 by fbarbera          #+#    #+#             */
/*   Updated: 2020/07/24 00:07:39 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int			flag_minus;
	int			flag_nul;
	int			flag_weght;
	int			flag_dot;
	int			flag_acc;
}				t_list;

int				ft_printf(const char *format, ...);
t_list			*ft_identy(const char *format, int *i, va_list p);
int				ft_atoip(const char *nptr);
int				ft_intlen(int n);
int				ft_strlen(char *str);
char			*ft_strchr(const char *str, int ch);
char			*ft_hex(size_t n, int bol);
int				ft_putchar(char c);
void			ft_putnbr(int nb);
int				ft_putstr(char *str);
void			ft_putunbr(unsigned int nb);
int				ft_ifdi(int n, t_list *flags);
int				ft_ifu(unsigned int n, t_list *flags);
int				ft_ifxx(char *n, t_list *flags);
int				ft_ifc(int n, t_list *flags);
int				ft_ifs(char *str, t_list *flags);
int				ft_ifp(void *pointer, t_list *flags);
char			*ft_substr(char *s, int start, size_t len);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_bzero(void *s, size_t n);

#endif
