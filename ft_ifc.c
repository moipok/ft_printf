/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 01:03:33 by fbarbera          #+#    #+#             */
/*   Updated: 2020/07/24 00:06:35 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_doweght(t_list *flags, int weght)
{
	int buf;

	buf = 0;
	if (flags->flag_minus && (flags->flag_weght - 1 > 0))
	{
		if (1 > flags->flag_acc)
			weght = flags->flag_weght - 1;
		while (weght > 0)
		{
			ft_putchar(' ');
			weght = weght - 1;
			buf++;
		}
	}
	return (buf);
}

int			ft_ifc(int n, t_list *flags)
{
	int weght;
	int buf;

	weght = 0;
	buf = 1;
	if (!flags->flag_minus && (flags->flag_weght - 1 > 0))
	{
		if (1 > flags->flag_acc)
			weght = flags->flag_weght - 1;
		while (weght > 0)
		{
			if (flags->flag_nul)
				ft_putchar('0');
			else
				ft_putchar(' ');
			weght = weght - 1;
			buf++;
		}
	}
	ft_putchar(n);
	buf += ft_doweght(flags, weght);
	return (buf);
}
