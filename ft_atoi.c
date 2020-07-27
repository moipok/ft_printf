/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 21:11:56 by fbarbera          #+#    #+#             */
/*   Updated: 2020/07/24 00:06:00 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_atoibig(const char *nptr, int *minus)
{
	int		len;

	len = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		len++;
		nptr++;
		if (len > 19 && *minus == 1)
			return (1);
		if (len > 19 && *minus == -1)
		{
			*minus = 0;
			return (2);
		}
	}
	return (0);
}

int			ft_atoip(const char *nptr)
{
	int		a;
	int		minus;

	a = 0;
	while (*nptr && (*nptr == '\n' || *nptr == '\t' || *nptr == ' ' ||
			*nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		nptr++;
	minus = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			return (0);
		nptr++;
	}
	if (ft_atoibig(nptr, &minus) == 1)
		return (-1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		a = a * 10 + *nptr - '0';
		nptr++;
	}
	return (a * minus);
}
