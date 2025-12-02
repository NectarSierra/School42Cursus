/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <worksailleznathan@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:05:25 by nsaillez          #+#    #+#             */
/*   Updated: 2024/11/05 11:30:09 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

char	*ft_tobase(unsigned long res, char *base);
int		ft_putnbr(int arg);
int		ft_uputnbr(unsigned int arg);
int		ft_sizeputnbr(int arg);
int		ft_sizeuputnbr(unsigned int arg);
int		ft_printf(const char *arg, ...);
int		ft_write_c(char arg);
int		ft_write_s(char *arg);
int		ft_write_p(void *arg);
int		ft_write_d(int arg);
int		ft_write_i(int arg);
int		ft_write_u(unsigned int arg);
int		ft_write_x(unsigned int arg);
int		ft_write_xupp(unsigned int arg);

#endif
