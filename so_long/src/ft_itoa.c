/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:39:44 by hzona             #+#    #+#             */
/*   Updated: 2021/11/02 18:24:23 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*min(char *c)
{
	c[0] = '-';
	c[1] = '2';
	c[2] = '1';
	c[3] = '4';
	c[4] = '7';
	c[5] = '4';
	c[6] = '8';
	c[7] = '3';
	c[8] = '6';
	c[9] = '4';
	c[10] = '8';
	c[11] = '\0';
	return (c);
}

char	*minus(char *c, int ten, int n)
{
	int	i;

	c[0] = '-';
	i = 1;
	n *= -1;
	while (ten >= 1)
	{
		c[i] = n / ten + '0';
		n = n - (ten * (c[i] - '0'));
		ten /= 10;
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*numb(int n, int mul, char *c, int ten)
{
	int	i;

	i = 0;
	if (n < 0)
		mul--;
	if (c == (void *)0)
		return ((void *)0);
	while (mul > 0)
	{
		ten *= 10;
		mul --;
	}
	if (n == -2147483648)
		return (min(c));
	else if (n < 0)
		return (minus(c, ten, n));
	while (ten >= 1)
	{
		c[i] = n / ten + '0';
		n = n - (ten * (c[i] - '0'));
		ten /= 10;
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_itoa(int n)
{
	int		i;
	int		mul;
	int		buf;
	char	*c;

	if (n > 10 && n < 10)
		return (numb(n, 0, 0, 1));
	i = 0;
	mul = 0;
	buf = n;
	if (buf < 0)
		mul++;
	if (buf == -2147483648)
		buf ++;
	if (buf < 0)
		buf *= -1;
	while (buf >= 10)
	{
		buf /= 10;
		mul++;
	}
	c = malloc(sizeof(char) * (mul + 2));
	return (numb(n, mul, c, 1));
}
