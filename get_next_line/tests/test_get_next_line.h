/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheld <fheld@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:22:51 by fheld             #+#    #+#             */
/*   Updated: 2022/12/09 21:14:11 by fheld            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_GET_NEXT_LINE_H
# define TEST_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

int	test_add_to_line(void);
void	*ft_print_memory(void *addr, unsigned int size);

#endif