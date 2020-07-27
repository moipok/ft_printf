/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex16.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:40:02 by fbarbera          #+#    #+#             */
/*   Updated: 2020/07/24 00:08:09 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strtoupper(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= 'a') && (s[i] <= 'z'))
			s[i] = (s[i] + ('A' - 'a'));
		i++;
	}
	return (s);
}

int			ft_intlen(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_reverse(char *s)
{
	int		i;
	int		j;
	char	swit;

	i = ft_strlen(s) - 1;
	j = 0;
	while (j <= i)
	{
		swit = s[i];
		s[i] = s[j];
		s[j] = swit;
		i--;
		j++;
	}
	return (s);
}

static char	*ft_createstr(size_t n)
{
	int				i;
	char			*a;

	if (n == 0)
	{
		if (!(a = ft_calloc(sizeof(char), 1 + 1)))
			return (0);
		a[0] = '0';
		return (a);
	}
	i = 0;
	while (n)
	{
		n = n / 16;
		i++;
	}
	if (!(a = ft_calloc(sizeof(char), i + 1)))
		return (0);
	return (a);
}

char		*ft_hex(size_t n, int bol)
{
	char			*a;
	unsigned int	i;
	size_t			nn;
	const	char	*s = "0123456789abcdef";

	i = 0;
	a = ft_createstr(n);
	nn = n;
	while (n)
	{
		a[i] = s[n % 16];
		n = n / 16;
		i++;
	}
	if (nn != 0)
		a[i] = '\0';
	if (bol == 0)
		return (ft_reverse(a));
	else
		return (ft_strtoupper(ft_reverse(a)));
}
