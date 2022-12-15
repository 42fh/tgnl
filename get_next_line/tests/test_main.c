/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheld <fheld@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:16:49 by fheld             #+#    #+#             */
/*   Updated: 2022/12/11 18:20:56 by fheld            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source/get_next_line.h"
#include "test_get_next_line.h"

void	putl(char *s)
{
	while (*s != '\n')
	{
		write(1, s, 1);
		s++;
	}
	write(1, s, 1);
}

void	test_helper_functions()
{
	printf("testing helper functions:\n");
	test_add_to_line();
	printf("\n\n");
}

int	main()
{
	char *p;
	//test_helper_functions();
	//int fd = open("f3.txt", O_RDONLY);
	int fd = 0;
	if (fd == -1)
		return (77);
	while ((p = get_next_line(fd)))
	{
		printf("%p\n", p);
		putl(p);
		free(p);
	}
	printf("%p\n", p);
	//close(fd);
	return (0);
}