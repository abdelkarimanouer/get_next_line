/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouer <aanouer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:23:13 by aanouer           #+#    #+#             */
/*   Updated: 2025/10/28 15:23:15 by aanouer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int	add_str(char *fullstr, unsigned int index, char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		fullstr[index++] = s[i++];
	return (index);
}

char    *ft_strdup(const char *s)
{
        int             i;
        char    *copy;
        size_t  len;

        if (!s)
                return (NULL);
        i = 0;
        len = ft_strlen(s);
        copy = malloc(len + 1);
        if (copy == NULL)
                return (NULL);
        while (s[i])
        {
                copy[i] = s[i];
                i++;
        }
        copy[i] = '\0';
        return (copy);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *sstr;
        size_t  i;
        size_t  lenstr;

        if (!s)
                return (NULL);
        lenstr = ft_strlen(s);
        if (start >= lenstr)
                return (ft_strdup(""));
        if (len > lenstr - start)
                len = lenstr - start;
        sstr = malloc(len + 1);
        if (!sstr)
                return (NULL);
        i = 0;
        while (i < len)
                sstr[i++] = s[start++];
        sstr[i] = '\0';
        return (sstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index;
	size_t	lens1;
	size_t	lens2;
	char	*fullstr;

	if (!s1 && !s2)
		return (NULL);
	index = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	fullstr = malloc((lens1 + lens2) + 1);
	if (fullstr == NULL)
		return (NULL);
	if (s1 != NULL)
		index = add_str(fullstr, 0, s1);
	if (s2 != NULL)
		index = add_str(fullstr, index, s2);
	fullstr[index] = '\0';
	return (fullstr);
}
