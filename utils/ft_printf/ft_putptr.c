/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:30:27 by astoll            #+#    #+#             */
/*   Updated: 2023/11/15 11:24:48 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(uintptr_t ptr)
{
	int	count;

	count = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		count++;
	}
	return (count);
}

static void	ft_ptrput(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_ptrput(ptr / 16);
		ft_ptrput(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_putptr(uintptr_t ptr)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
	{
		ft_ptrput(ptr);
		count += ft_ptrlen(ptr);
	}
	return (count);
}
