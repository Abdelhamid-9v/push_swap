/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:27:52 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/17 12:51:16 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			a;

	a = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == a)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == a)
		return ((char *)&s[i]);
	return (NULL);
}

static char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	l;
	char	*p;

	l = 0;
	l = ft_strlen(s1);
	p = malloc(l + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*bib;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup (s2));
	if (!s2)
		return (ft_strdup (s2));
	i = -1;
	j = -1;
	bib = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!bib)
		return (NULL);
	while (s1[++i])
		bib[i] = s1[i];
	while (s2[++j])
		bib[i++] = s2[j];
	bib[i] = '\0';
	return (bib);
}
