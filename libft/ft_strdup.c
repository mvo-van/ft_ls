/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:59:02 by smoreno-          #+#    #+#             */
/*   Updated: 2018/12/05 21:59:06 by smoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*cp;
	size_t	len;
	size_t	i;
	char	*s12;

	s12 = (char *)s1;
	i = 0;
	len = ft_strlen(s12);
	if (!(cp = (char*)malloc(sizeof(*s12) * (len + 1))))
		return (NULL);
	while (s12[i])
	{
		cp[i] = s12[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
