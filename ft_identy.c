/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 22:23:55 by fbarbera          #+#    #+#             */
/*   Updated: 2020/07/24 00:06:16 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_lenatoi(const char *str)
{
	int i;

	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		i++;
		str++;
	}
	return (i);
}

static t_list	*ft_zero_list(void)
{
	t_list *flags;

	if (!(flags = malloc((sizeof(t_list)))))
		return (NULL);
	flags->flag_minus = 0;
	flags->flag_nul = 0;
	flags->flag_weght = 0;
	flags->flag_dot = 0;
	flags->flag_acc = 0;
	return (flags);
}

static t_list	*ft_i3(const char *format, int *i, va_list p, t_list *flags)
{
	if (format[*i] == '.')
	{
		flags->flag_dot++;
		flags->flag_nul = 0;
		*i = *i + 1;
		if (format[*i] == '*')
		{
			flags->flag_acc = va_arg(p, int);
			*i = *i + 1;
			if (flags->flag_acc < 0)
				flags->flag_dot--;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
		{
			flags->flag_acc = ft_atoip(format + *i);
			*i = *i + ft_lenatoi(format + *i);
		}
	}
	return (flags);
}

static t_list	*ft_i2(const char *format, int *i, va_list p, t_list *flags)
{
	if (format[*i] == '*')
	{
		flags->flag_weght = va_arg(p, int);
		*i = *i + 1;
		if (flags->flag_weght < 0)
		{
			flags->flag_weght = (-1) * flags->flag_weght;
			flags->flag_minus++;
			flags->flag_nul = 0;
		}
	}
	else if (format[*i] >= '0' && format[*i] <= '9')
	{
		flags->flag_weght = ft_atoip(format + *i);
		*i = *i + ft_lenatoi(format + *i);
	}
	return (ft_i3(format, i, p, flags));
}

t_list			*ft_identy(const char *format, int *i, va_list p)
{
	t_list	*flags;

	if (!(flags = ft_zero_list()))
		return (NULL);
	*i = *i + 1;
	if (format[*i] == '0')
	{
		flags->flag_nul = 1;
		*i = *i + 1;
	}
	if (format[*i] == '-')
	{
		flags->flag_minus++;
		flags->flag_nul = 0;
		*i = *i + 1;
	}
	while (format[*i] == '0' || format[*i] == '-')
	{
		if (format[*i] == '-')
			flags->flag_nul = 0;
		*i = *i + 1;
	}
	return (ft_i2(format, i, p, flags));
}
