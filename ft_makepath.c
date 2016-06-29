/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makepath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syusof <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 00:45:57 by syusof            #+#    #+#             */
/*   Updated: 2016/06/29 16:07:38 by syusof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lem-in.h"

char	*ft_makepath(char *str1,char *str2)
{
	char*str;
	int len;
	int	i;

	len = ft_strlen(str1);
	str = ft_strnew(len + 1 + 1);
	i = 0;
	while (i < len)
	{
		str[i] = str1[i];
		i++;
	}
	str[i] = '/';
	i++;
	str[i] = 0;
	str = ft_strjoin(str,str2);
	return (str);
}
