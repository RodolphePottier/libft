/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:34:33 by rpottier          #+#    #+#             */
/*   Updated: 2021/08/11 17:39:13 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	base_length;

	i = 0;
	base_length = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < ' ' || base[i] > '~')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i > 1)
		return (i);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_length;
	int				i;
	unsigned int	nb;

	base_length = check_base(base);
	i = 0;
	if (base_length)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nb = -nbr;
		}
		else
			nb = nbr;
		if (nb >= base_length)
		{
			ft_putnbr_base(nb / base_length, base);
			nb = nb % base_length;
		}
		ft_putchar(base[nb]);
	}
}
