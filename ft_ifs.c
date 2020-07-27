/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 01:46:38 by fbarbera          #+#    #+#             */
/*   Updated: 2020/07/24 00:06:46 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_stracc(char *str, int len)
{
	int lenstr;

	if ((lenstr = len - ft_strlen(str)) > 0)
		str[len] = '\0';
}

static	int		ft_dominus(int len, t_list *flags)
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
			buf++;
			weght--;
		}
	}
	return (buf);
}

static	int		ft_actuallen(int n1, int n2)
{
	if (!n2)
		return (n1);
	if (n1 > n2)
		return (n2);
	else
		return (n1);
}

static int		ft_doweght(t_list *flags, char *s, int acc)
{
	int buf;
	int weght;

	buf = 0;
	if (((flags->flag_dot) && (flags->flag_acc - ft_strlen(s) < 0)) \
	|| ((flags->flag_dot) && (!flags->flag_acc)))
	{
		s[flags->flag_acc] = '\0';
		acc = flags->flag_acc;
	}
	if (!flags->flag_minus && \
	(flags->flag_weght > ft_actuallen(ft_strlen(s), acc)))
	{
		weght = flags->flag_weght - ft_actuallen(ft_strlen(s), acc);
		while (weght > 0)
		{
			if (flags->flag_nul)
				ft_putchar('0');
			else
				ft_putchar(' ');
			buf++;
			weght = weght - 1;
		}
	}
	return (buf);
}

int				ft_ifs(char *str, t_list *flags)
{
	int		acc;
	char	*s;
	int		buf;

	if (str == NULL)
		s = ft_substr("(null)", 0, 6);
	else
		s = ft_substr(str, 0, ft_strlen(str));
	acc = 0;
	buf = ft_doweght(flags, s, acc);
	ft_putstr(s);
	buf += ft_strlen(s);
	buf += ft_dominus(ft_strlen(s), flags);
	free(s);
	return (buf);
}
