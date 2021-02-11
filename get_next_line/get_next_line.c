/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:32:11 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/11 12:50:25 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(char **line)
{
	char	*buf;
	int		res;
	int		i;

	i = 0;
	if (read(0, buf, 0) < 0 || !line || !(buf = malloc(100000)))
		return (-1);
	while ((res = read(0, &buf[i], 1)) > 0 && buf[i] != '\n')
		i++;
	buf[i] = '\0';
	res != -1 ? *line = buf : free(buf);
	return (res);
}