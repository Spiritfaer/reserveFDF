/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 22:08:26 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/26 22:08:27 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' ||
		c == '\f' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

static int		ft_isdigit_base(char c, int base)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c >= 65 && c <= 65 + (base - 11))
		return (2);
	if (c >= 97 && c <= 97 + (base - 11))
		return (3);
	return (0);
}

int				ft_atoi_base(const char *str, int str_base)
{
	int neg;
	int res;
	int flag;

	neg = 1;
	res = 0;
	flag = 2;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		neg = *str++ == '-' ? -1 : 1;
	while (*str && str_base == 16 && flag--)
		str++;
	while (*str && ft_isdigit_base(*str, str_base))
	{
		res *= str_base;
		if (ft_isdigit_base(*str, str_base) == 1)
			res += *str - 48;
		if (ft_isdigit_base(*str, str_base) == 2)
			res += *str - 55;
		if (ft_isdigit_base(*str, str_base) == 3)
			res += *str - 87;
		str++;
	}
	return (res * neg);
}
