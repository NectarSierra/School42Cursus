/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <worksailleznathan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:26:04 by nsaillez          #+#    #+#             */
/*   Updated: 2024/11/06 10:02:58 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_specifier(char format, va_list args)
{
	if (format == 'c')
		return (ft_write_c(va_arg(args, int)));
	else if (format == 's')
		return (ft_write_s(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_write_p(va_arg(args, void *)));
	else if (format == 'd')
		return (ft_write_d(va_arg(args, int)));
	else if (format == 'i')
		return (ft_write_i(va_arg(args, int)));
	else if (format == 'u')
		return (ft_write_u(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_write_x(va_arg(args, unsigned int)));
	else if (format == 'X')
		return (ft_write_xupp(va_arg(args, unsigned int)));
	else if (format == '%')
	{
		return (write(1, "\%", 1));
		return (1);
	}
	return (0);
}

int	ft_writeargs(va_list args, const char *strwformat)
{
	int	writelen;
	int	res;

	writelen = 0;
	while (*strwformat)
	{
		if (*strwformat == '%')
		{
			res = format_specifier(*(strwformat + 1), args);
			if (res == -1)
				return (-1);
			writelen += res;
			strwformat++;
		}
		else
		{
			if (write(1, strwformat, 1) == -1)
				return (-1);
			writelen++;
		}
		strwformat++;
	}
	return (writelen);
}

int	ft_printf(const char *strwformat, ...)
{
	va_list		args;
	int			res;

	va_start(args, strwformat);
	res = ft_writeargs(args, strwformat);
	if (res == -1)
		return (-1);
	va_end(args);
	return (res);
}

/*int	main()
{
	unsigned int j = 100;
	int minint = -2000;
	char	*ptr;
	ptr = "Ur_good!";
	printf("[size: %i]\n",printf("%%,%c,%d,%u,%s,%x,%X,%p",
	ptr[0],minint,j,ptr,j,j,ptr));
	printf("[size: %i]\n",ft_printf("%%,%c,%d,%u,%s,%x,%X,%p",
	ptr[0],minint,j,ptr,j,j,ptr));
	printf("%i\n",ft_printf("%x\n",-10));
	printf("%i\n",printf("%x\n",-10));
	printf("% i\n", j);
    ft_printf("% i\n", j);
}*/
