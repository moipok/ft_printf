/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifdi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:38:46 by fbarbera          #+#    #+#             */
/*   Updated: 2020/07/24 00:07:02 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_doweght(int n, t_list *flags)
{
	int weght;
	int buf;

	buf = 0;
	if (!flags->flag_nul && !flags->flag_minus && \
		((flags->flag_weght - flags->flag_acc > 0) || \
		(flags->flag_weght - ft_intlen(n) > 0)))
	{
		if (ft_intlen(n) > flags->flag_acc)
			weght = flags->flag_weght - ft_intlen(n);
		else
			weght = flags->flag_weght - flags->flag_acc;
		if (n < 0)
			weght--;
		while (weght > 0)
		{
			ft_putchar(' ');
			buf++;
			weght = weght - 1;
		}
	}
	return (buf);
}

static int	ft_ifnminus(int *n, int *weght, t_list *flags)
{
	int buf;

	buf = 0;
	if (*n < 0)
	{
		ft_putchar('-');
		buf = buf + 1;
		*n = -*n;
		*weght = *weght - 1;
		flags->flag_weght--;
	}
	return (buf);
}

static int	ft_doacc(int n, t_list *flags, int *buf)
{
	int acc;
	int weght;

	weght = (flags->flag_weght - ft_intlen(n));
	if (((flags->flag_acc - ft_intlen(n)) > 0) || \
	((flags->flag_nul) && (weght > 0)))
	{
		acc = flags->flag_acc - ft_intlen(n);
		*buf = *buf + ft_ifnminus(&n, &weght, flags);
		if (acc < weght && flags->flag_nul)
			acc = weght;
		while (acc > 0)
		{
			ft_putchar('0');
			acc = acc - 1;
			*buf = *buf + 1;
		}
	}
	else if (n < 0)
		*buf = *buf + 1;
	return (n);
}

static int	ft_dominus(int n, t_list *flags)
{
	int weght;
	int buf;

	buf = 0;
	if (flags->flag_minus && (flags->flag_weght > ft_intlen(n) \
	|| flags->flag_weght > flags->flag_acc))
	{
		if (ft_intlen(n) > flags->flag_acc)
			weght = flags->flag_weght - ft_intlen(n);
		else
			weght = flags->flag_weght - flags->flag_acc;
		if (n < 0)
			weght--;
		while (weght > 0)
		{
			ft_putchar(' ');
			buf++;
			weght = weght - 1;
		}
	}
	return (buf);
}

int			ft_ifdi(int n, t_list *flags)
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
		ft_putnbr(n);
		buf += ft_intlen(n);
	}
	buf += ft_dominus(n, flags);
	return (buf);
}
