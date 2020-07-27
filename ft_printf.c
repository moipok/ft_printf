/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:48:43 by fbarbera          #+#    #+#             */
/*   Updated: 2020/07/24 00:07:32 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_do_case(const char *format, int *i, t_list *flags, va_list p)
{
	int buf;

	buf = 0;
	if (format[*i] == '%')
		buf = ft_ifc('%', flags);
	else if (format[*i] == 'c')
		buf = ft_ifc(va_arg(p, int), flags);
	else if (format[*i] == 's')
		buf = ft_ifs(va_arg(p, char*), flags);
	else if (format[*i] == 'p')
		buf = ft_ifp(va_arg(p, void *), flags);
	else if (format[*i] == 'd' || format[*i] == 'i')
		buf = ft_ifdi(va_arg(p, int), flags);
	else if (format[*i] == 'u')
		buf = ft_ifu(va_arg(p, unsigned int), flags);
	else if (format[*i] == 'x')
		buf = ft_ifxx(ft_hex(va_arg(p, unsigned int), 0), flags);
	else if (format[*i] == 'X')
		buf = ft_ifxx(ft_hex(va_arg(p, unsigned int), 1), flags);
	free(flags);
	return (buf);
}

static int	ft_end(va_list p, t_list *flags)
{
	va_end(p);
	free(flags);
	return (-1);
}

int			ft_printf(const char *format, ...)
{
	va_list	p;
	t_list	*flags;
	int		i;
	int		buf;

	va_start(p, format);
	i = 0;
	buf = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(flags = ft_identy(format, &i, p)))
				return (-1);
			if (ft_strchr("cspdiuxX%%", format[i]))
				buf = buf + ft_do_case(format, &i, flags, p);
			else
				return (ft_end(p, flags));
		}
		else
			buf += ft_putchar(format[i]);
		i++;
	}
	va_end(p);
	return (buf);
}
