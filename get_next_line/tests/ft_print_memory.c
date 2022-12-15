/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhled <fheld@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:07:45 by fhled             #+#    #+#             */
/*   Updated: 2022/06/29 18:12:41 by fhled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	d10_to_d16(unsigned long int n)
{
	char	c;

	c = 'E';
	if (n <= 9)
		c = '0' + n;
	if (n >= 10 && n <= 15)
		c = 'a' - 10 + n;
	write(1, &c, 1);
}

void	ft_pt_addr(void *addr)
{
	unsigned long int	n;
	unsigned long int	p;

	n = (unsigned long int) addr;
	p = 1152921504606846976;
	while (p > 0)
	{
		d10_to_d16(n / p);
		n = n % p;
		p = p / 16;
	}
	write(1, ": ", 2);
	return ;
}

void	ft_pt_bytes(void *addr, unsigned int n)
{
	unsigned char	*number;
	unsigned int	count;

	number = addr;
	count = 0;
	while (count < n)
	{
		d10_to_d16(*(number + count) / 16);
		d10_to_d16(*(number + count) % 16);
		if (count % 2 == 1)
			write(1, " ", 1);
		count ++;
	}
	while (count < 16)
	{
		write(1, "  ", 2);
		if (count % 2 == 1)
			write(1, " ", 1);
		count ++;
	}
	return ;
}

void	ft_pt_printable(void *addr, unsigned int n)
{
	char			*p;
	char			c;
	unsigned int	count;

	p = addr;
	c = *p;
	count = 0;
	while (count < n)
	{
		if (c >= 32 && c <= 126)
			write(1, p, 1);
		else
			write(1, ".", 1);
		count ++;
		p ++;
		c = *p;
	}
	return ;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	count;

	count = 0;
	while (count < size)
	{
		ft_pt_addr(addr + count);
		if (size < count + 16)
			ft_pt_bytes(addr + count, size - count);
		else
			ft_pt_bytes(addr + count, 16);
		if (size < count + 16)
			ft_pt_printable(addr + count, size - count);
		else
			ft_pt_printable(addr + count, 16);
		write(1, "\n", 1);
		count += 16;
	}
	return (addr);
}
