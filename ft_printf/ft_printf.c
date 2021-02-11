/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 04:12:40 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/11 18:40:04 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int g_len = 0;

typedef struct		s_prm
{
	int				prec;
	char			type;
	int				width;
	long long		i_value;
	unsigned int	h_value;
	char*			s_value;
	int				prec_exist;

	int				arg_len;
	int				spaces;
	int				zeros;
} 					t_prm;

void	set_defaults(t_prm *prm)
{
	prm->type = 0;
	prm->prec = 0;
	prm->width = 0;
	prm->i_value = 0;
	prm->s_value = 0;
	prm->prec_exist = 0;
	prm->h_value = 0;
	prm->zeros = 0;
	prm->spaces = 0;
	prm->arg_len = 0;
}

int		ft_atoi(const char *s, int *res)
{
	int i;

	i = 0;
	*res = 0;
	while (s[i] >= '0' && s[i] <= '9')
		*res = *res * 10 + (s[i++] - '0');
	return (i);
}

void	ft_putstrn(const char *str, int len)
{
	if (str)
		g_len += write(1, str, len);
}

void	ft_putchar(char c)
{
	g_len += write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int		ft_numlen(long long number, int base)
{
	int count;

	count = 0;
	while (number != 0)
	{
		number /= base;
		count++;
	}
	return (count);
}

int		ft_itoa_base(unsigned long long num, unsigned int base)
{
	if (num / base != 0)
	{
		ft_itoa_base(num / base, base);
	}
	ft_putchar(num % base > 9 ? (num % base) - 10 + 'a' : (num % base) + '0');
	return (0);
}

int		get_pos_or_zero(long long num)
{
	return (num < 0 ? 0 : num);
}

int		get_parameters(const char *s, int *index, t_prm *prm)
{
	int i;

	i = 0;
	i += ft_atoi(&s[0], &prm->width);
	if (s[i] == '.' && i++)
	{
		i += ft_atoi(&s[i], &prm->prec);
		prm->prec_exist = 1;
	}
	prm->type = s[i];
	*index += i + 1;

	return (0);
}

int		get_arguments(t_prm *prm, va_list ap)
{
	if (prm->type == 'd')
	{
		prm->i_value = va_arg(ap, int);
	}
	else if (prm->type == 'x')
	{
		prm->h_value = (unsigned int)va_arg(ap, int);
	}
	else if (prm->type == 's')
	{
		prm->s_value = va_arg(ap, char *);
		if (!prm->s_value)
			prm->s_value = "(null)";
	}
	else
		return (-1);
	return (0);
}

int		calculate_print_params(t_prm *prm)
{
	if (prm->type == 'd')
		prm->arg_len = ft_numlen(prm->i_value, 10);
	else if (prm->type == 'x')
		prm->arg_len = ft_numlen(prm->h_value, 16);
	else if (prm->type == 's')
		prm->arg_len = prm->prec_exist ? prm->prec : ft_strlen(prm->s_value);
	
	if (prm->prec_exist)
		prm->zeros = get_pos_or_zero(prm->prec - prm->arg_len);
	
	prm->spaces = get_pos_or_zero(prm->width - prm->arg_len - prm->zeros - (prm->i_value < 0));
	return (0);
}

int		print_spaces(t_prm *prm)
{
	calculate_print_params(prm);
	while (prm->spaces--)
		ft_putchar(' ');
	if (prm->i_value < 0)
	{
		ft_putchar('-');
		prm->i_value *= -1;
	}
	while (prm->type != 's' && prm->zeros--)
		ft_putchar('0');	
	return (0);
}

int		print_values(t_prm *prm)
{
	print_spaces(prm);
	if (prm->type == 'd')
	{
		if (!(prm->prec_exist && prm->prec == 0 && prm->i_value == 0))
			ft_itoa_base(prm->i_value, 10);
	}
	else if (prm->type == 'x')
	{
		if (!(prm->prec_exist && prm->prec == 0 && prm->h_value == 0))
			ft_itoa_base(prm->h_value, 16);
	}
	else if (prm->type == 's')
	{
		ft_putstrn(prm->s_value, prm->arg_len);
	}
	else
		return (-1);
	return (0);
}

int		ft_printf(const char *format, ... )
{
	va_list ap;
	t_prm prm;
	int start;
	int i;

	i = 0;
	start = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_putstrn(&format[start], i - start);
			set_defaults(&prm);
			i++;
			if (get_parameters(&format[i], &i, &prm))
				return (-1);
			if (get_arguments(&prm, ap))
				return (-1);
			if (print_values(&prm))
				return (-1);
			start = i;
		}
		i++;
	}
	va_end(ap);
	ft_putstrn(&format[start], i - start);
	return (g_len);
}