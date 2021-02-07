/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 01:44:33 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/06 02:07:48 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_in_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int is_first(char *str, int index)
{
	int i;

	i = 0; 
	while (i < index)
	{
		if (str[i] == str[index])
			return (0);
		i++;
	}
	return (1);
}

int ft_union(char **argv)
{
	int i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (is_first(argv[1], i))
			write(1, &argv[1][i], 1);
		i++;
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (is_first(argv[2], i) && !is_in_str(argv[1], argv[2][i]))
			write(1, &argv[2][i], 1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv);
	}
	write(1, "\n", 1);
	return (0);
}