/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_overflow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:18:46 by nsaillez          #+#    #+#             */
/*   Updated: 2025/02/04 12:05:17 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../push_swap.h"

/* This function check if a char transformed to a 
int will overflow in that case it will return -1 */

int	overflow_check(int res, int digit, int isneg)
{
	if (isneg == -1)
	{
		if ((res >= 214748364) && ((res > 214748364) || (digit > 8)))
			return (-1);
	}
	else
	{
		if ((res >= 214748364) && ((res > 214748364) || (digit > 7)))
			return (-1);
	}
	return (0);
}

/* 
**	This function is a modified ft_atoi that check 
**  for overflow && if only a sign (+/-) is readed without a number following it 
**	it return -1 (error) 
*/

int	char_to_int_overflow(char *str)
{
	int	i;
	int	res;
	int	isneg;

	i = 0;
	isneg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg = -1;
		i++;
	}
	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (overflow_check(res, (str[i] - '0'), isneg) == -1)
			return (-1);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] || str[i - 1] == '-' || str[i - 1] == '+')
		return (-1);
	return (0);
}
