/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 01:03:22 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/06 01:41:34 by mhufflep         ###   ########.fr       */
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

int inter(char **argv)
{
	int i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (is_first(argv[1], i) && is_in_str(argv[2], argv[1][i]))
		{
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		inter(argv);
	}
	write(1, "\n", 1);
	return (0);
}