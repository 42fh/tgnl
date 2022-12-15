/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_full.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheld <fheld@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:36:04 by fheld             #+#    #+#             */
/*   Updated: 2022/12/15 12:21:35 by fheld            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "source/get_next_line.h"

static void get_from_stdin(void)
{
	char	*line2;

	line2 = (char *)1;
	while (line2)
	{
		line2 = get_next_line(0);
		if (line2 == 0)
		{
			free(line2);
			return ;
		}
		printf("%s", line2);
		free(line2);
	}	
}

//printf("🌟");
int main(int argc, char const *argv[])
{
	//printf("BUFFER_SIZE is eq to: %d\n", BUFFER_SIZE);
	FILE	*fp;
	char	*line1;
	char	*line2;
	size_t	len1;
	int		fd;
	ssize_t	n;
	
	if (argc == 1)
	{
		get_from_stdin();
		return (0);
	}
	else if (argc == 2)
	{
		fp = fopen(argv[1], "r");
		if (fp == NULL)
			printf("err fopen\n");
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			printf("err open\n");
	}
	else
	{
		printf("no input means read from stdin, one input means open said file\n");
		return (0);
	}
	len1 = 0;

	line1 = "placeholder";
	line2 = "placeholder";
	while (line1 || line2)
	{
		line1 = NULL;
		n = getline(&line1, &len1, fp);
		line2 = get_next_line(fd);
		if (n < 0 || line2 == 0)
		{
			free(line1);
			free(line2);
			break ;
		}
		if (memcmp(line1, line2, n) != 0 || strlen(line1) != strlen(line2))
		{
			printf("\033[0;31m==disagreement==\033[0m\n");
			printf("memcmp = %d\n", memcmp(line1, line2, n));
			printf("getline: {%s}\n", line1);
			printf("ft_gnl : {%s}\n", line2);
		}
		else
			printf("-");
		free(line1);
		free(line2);
	}
	fclose(fp);
	close(fd);
}