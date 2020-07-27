/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 05:03:47 by fbarbera          #+#    #+#             */
/*   Updated: 2020/07/16 05:03:49 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_doweght(t_list *flags, int len)
{
	int		weght;
	int		buf;

	buf = 0;
	if (flags->flag_weght > len)
	{
		weght = flags->flag_weght - len;
		while (weght)
		{
			ft_putchar(' ');
			buf++;
			weght--;
		}
	}
	return (buf);
}

static	char	*ft_doline(void *pointer, t_list *flags)
{
	size_t	p;
	char	*s;

	if (pointer == NULL)
	{
		if (flags->flag_dot && (flags->flag_acc == 0))
			s = ft_substr("", 0, 0);
		else
			s = ft_substr("0", 0, 1);
	}
	else
	{
		p = *(size_t *)&pointer;
		s = ft_hex(p, 0);
	}
	return (s);
}

int				ft_ifp(void *pointer, t_list *flags)
{
	char	*s;
	int		buf;
	int		acc;

	buf = 2;
	acc = 0;
	s = ft_doline(pointer, flags);
	if (!flags->flag_minus)
		buf += ft_doweght(flags, ft_strlen(s) + 2);
	ft_putstr("0x");
	if (flags->flag_acc - ft_strlen(s) > 0)
	{
		acc = flags->flag_acc - ft_strlen(s);
		while (acc)
		{
			ft_putchar('0');
			acc--;
			buf++;
		}
	}
	buf += ft_putstr(s);
	if (flags->flag_minus)
		buf += ft_doweght(flags, ft_strlen(s) + 2);
	free(s);
	return (buf);
}
