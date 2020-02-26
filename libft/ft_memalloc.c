/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 08:16:46 by smoreno-          #+#    #+#             */
/*   Updated: 2018/11/13 08:34:25 by smoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*pmem;

	pmem = (void *)malloc(size * sizeof(size_t));
	if (!pmem)
		return (NULL);
	ft_bzero(pmem, size);
	return (pmem);
}
