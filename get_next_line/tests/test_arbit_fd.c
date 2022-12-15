/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_arbit_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheld <fheld@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:36:04 by fheld             #+#    #+#             */
/*   Updated: 2022/12/14 12:34:04 by fheld            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "source/get_next_line.h"

static void	sample(int fd)
{
	char	*c;
	c = get_next_line(fd);
	if (c != NULL)
		printf("disagreement fd = %d\n", fd);
}


//printf("🌟");
int main(void)
{
	printf("\narbitrary fd: ");
	sample(10);
	sample(100);
	sample(-1);
	sample(-100);
	printf("done\n");
	return (0);
}