/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsauva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:47:42 by matsauva          #+#    #+#             */
/*   Updated: 2025/01/15 22:21:23 by matsauva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	process_format(char format, va_list *args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	else if (format == 'x')
		return (ft_puthex(va_arg(*args, t_ui), "0123456789abcdef", 0));
	else if (format == 'X')
		return (ft_puthex(va_arg(*args, t_ui), "0123456789ABCDEF", 0));
	else if (format == 'p')
		return (ft_puthex((t_ul)va_arg(*args, void *), "0123456789abcdef", 1));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += process_format(format[i + 1], &args);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
