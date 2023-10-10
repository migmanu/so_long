/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:04:54 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/08/18 16:10:07 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	type_check(char c)
{
	int	a;

	a = c;
	if ((a >= 9 && a <= 13) || a == 32)
		return (3);
	if (a == 45)
		return (2);
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (type_check(str[i]) == 3)
		i++;
	if (str[i] == '+' && type_check(str[i + 1]) == 1)
		i++;
	if (type_check(str[i]) == 2)
	{
		sign *= -1;
		i++;
	}
	while (type_check(str[i]) == 1)
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}
/*
int	main(void)
{
	char	*nptr = "\t\n\r\v\f  2147483999 \n";
	printf("original:%ld\n\n", atol(nptr));
	printf("copy:%ld", ft_atol(nptr));

	return (0);
}*/
