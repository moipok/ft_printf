/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 23:40:53 by fbarbera          #+#    #+#             */
/*   Updated: 2020/07/12 23:40:55 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_uintlen(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_doweght(unsigned int n, t_list *flags)
{
	int weght;
	int buf;

	buf = 0;
	if (!flags->flag_nul && !flags->flag_minus && \
		((flags->flag_weght - flags->flag_acc > 0) || \
		(flags->flag_weght - ft_uintlen(n) > 0)))
	{
		if (ft_uintlen(n) > flags->flag_acc)
			weght = flags->flag_weght - ft_uintlen(n);
		else
			weght = flags->flag_weght - flags->flag_acc;
		while (weght > 0)
		{
			ft_putchar(' ');
			weght = weght - 1;
			buf++;
		}
	}
	return (buf);
}

static int	ft_doacc(unsigned int n, t_list *flags, int *buf)
{
	int acc;
	int weght;

	weght = (flags->flag_weght - ft_uintlen(n));
	if (((flags->flag_acc - ft_uintlen(n)) > 0) || \
	((flags->flag_nul) && (weght > 0)))
	{
		acc = flags->flag_acc - ft_uintlen(n);
		if (acc < weght && flags->flag_nul)
			acc = weght;
		while (acc > 0)
		{
			ft_putchar('0');
			acc = acc - 1;
			*buf = *buf + 1;
		}
	}
	return (n);
}

static int	ft_dominus(unsigned int n, t_list *flags)
{
	int weght;
	int buf;

	buf = 0;
	if (flags->flag_minus && (flags->flag_weght > ft_uintlen(n) \
	|| flags->flag_weght > flags->flag_acc))
	{
		if (ft_uintlen(n) > flags->flag_acc)
			weght = flags->flag_weght - ft_uintlen(n);
		else
			weght = flags->flag_weght - flags->flag_acc;
		while (weght > 0)
		{
			ft_putchar(' ');
			weght = weght - 1;
			buf++;
		}
	}
	return (buf);
}

int			ft_ifu(unsigned int n, t_list *flags)
{
	int buf;

	buf = ft_doweght(n, flags);
	n = ft_doacc(n, flags, &buf);
	if ((n == 0) && (flags->flag_acc == 0) && \
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
		ft_putunbr(n);
		buf += ft_uintlen(n);
	}
	buf += ft_dominus(n, flags);
	return (buf);
}
