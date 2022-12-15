/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_add_to_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheld <fheld@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:13:00 by fheld             #+#    #+#             */
/*   Updated: 2022/12/09 21:06:47 by fheld            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_get_next_line.h"

char	*add_to_line(char *old, size_t size_old, char *add, size_t size_add);

int	test_add_to_line(void)
{
	printf("add_to_line: \n");
	char	*p;
	char	str[15] = "BBBBBBBBBBBBBBB";

	p = malloc (15);
	if (!p)
		return (0);
	memset(p, 'A', 15);
	p = add_to_line(p, 15, str, 15);
	write(1, p, 30);
	free(p);
	printf("\n\n");
	return (0);
}