/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:17:44 by astoll            #+#    #+#             */
/*   Updated: 2023/11/15 11:20:24 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static void	ft_puthexa(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_puthexa(n / 16, format);
		ft_puthexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar((n + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((n - 10 + 'a'));
			if (format == 'X')
				ft_putchar((n - 10 + 'A'));
		}
	}
}

int	ft_puthex(unsigned int n, const char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthexa(n, format);
	return (ft_hexlen(n));
}
