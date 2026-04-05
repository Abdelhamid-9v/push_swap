/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:55:31 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/16 19:00:54 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*bib;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	bib = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (!bib)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		bib[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 		bib[i++] = s2[j++];
// 	bib[i] = '\0';
// 	return (bib);
// }
