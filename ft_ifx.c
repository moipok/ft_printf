/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:40:21 by fbarbera          #+#    #+#             */
/*   Updated: 2020/07/24 00:07:18 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_doweght(char *n, t_list *flags, int *buf)
{
	int weght;

	weght = 0;
	if (!flags->flag_nul && !flags->flag_minus && \
	((flags->flag_weght - flags->flag_acc > 0) || \
	(flags->flag_weght - ft_strlen(n) > 0)))
	{
		if (ft_strlen(n) > flags->flag_acc)
			weght = flags->flag_weght - ft_strlen(n);
		else
			weght = flags->flag_weght - flags->flag_acc;
		while (weght > 0)
		{
			ft_putchar(' ');
			weght = weght - 1;
			*buf = *buf + 1;
		}
	}
	return (weght);
}

static int	ft_dominus(int len, t_list *flags)
{
	int weght;
	int buf;

	buf = 0;
	if (flags->flag_minus && len < flags->flag_weght)
	{
		weght = flags->flag_weght - len;
		while (weght)
		{
			ft_putchar(' ');
			weght--;
			buf++;
		}
	}
	return (buf);
}

static int	ft_donul(t_list *flags, char *n, int *weght)
{
	int acc;
	int buf;

	buf = 0;
	if (((acc = (flags->flag_acc - ft_strlen(n))) > 0) || \
	((flags->flag_nul) && \
	((*weght = (flags->flag_weght - ft_strlen(n))) > 0)))
	{
		if (acc < *weght && flags->flag_nul)
			acc = *weght;
		*weght = acc;
		while (acc > 0)
		{
			ft_putchar('0');
			acc = acc - 1;
			buf++;
		}
	}
	return (buf);
}

int			ft_ifxx(char *n, t_list *flags)
{
	int weght;
	int buf;

	buf = 0;
	weght = ft_doweght(n, flags, &buf);
	buf += ft_donul(flags, n, &weght);
	if ((n[0] == '0') && (flags->flag_acc == 0) && \
	(flags->flag_dot))
	{
		if (flags->flag_weght)
		{
			ft_putchar(' ');
			buf++;
		}
	}
	else
	{
		ft_putstr(n);
		buf += ft_strlen(n);
	}
	buf += ft_dominus(weght + ft_strlen(n), flags);
	free(n);
	return (buf);
}
