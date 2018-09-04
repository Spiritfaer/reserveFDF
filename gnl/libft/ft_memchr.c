/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:38:30 by istalevs          #+#    #+#             */
/*   Updated: 2017/12/13 12:37:06 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *end;

	end = (unsigned char*)s + n;
	while (n-- && !(*(unsigned char*)s == (unsigned char)c))
		s++;
	if ((unsigned char*)s >= end)
		return (NULL);
	if (*(unsigned char*)s == (unsigned char)c)
		return ((void*)s);
	return (NULL);
}
