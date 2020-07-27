/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <login@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 04:14:51 by fbarbera          #+#    #+#             */
/*   Updated: 2020/05/24 01:10:40 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlensub(char *s, int start, int len)
{
	int	i;

	i = 0;
	while (s[start + i] && i < len)
		i++;
	return (i);
}

char		*ft_substr(char *s, int start, size_t len)
{
	char			*str;
	unsigned	int	min;
	unsigned	int	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		if (!(str = ft_calloc(1, sizeof(char))))
			return (0);
		return (str);
	}
	min = ft_strlen(s) - start;
	if (min < len)
		len = min;
	i = ft_strlensub(s, start, len);
	if (!(str = ft_calloc(sizeof(char ), i + 1)))
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
