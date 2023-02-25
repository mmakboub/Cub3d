/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:15:36 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/25 23:41:55 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	size_t	firstc;
	char	*newstr;

	firstc = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		newstr = malloc(1);
		if (!newstr)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (firstc < len && start < ft_strlen(s))
	{
		newstr[firstc++] = s[start++];
	}
	newstr[firstc] = '\0';
	return (newstr);
}

char	*remove_caract(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed_str = ft_substr(s1, start, end - start);
	if (!trimmed_str)
		return (NULL);
	return (trimmed_str);
}

char	*remove_prefix(char *line, char *prefix)
{
	char	*substring;
	size_t	len_prefix;

	len_prefix = strlen(prefix);
	substring = malloc(sizeof(char) * (ft_strlen(line) - len_prefix + 1));
	if (!substring)
		return (NULL);
	if (strncmp(line, prefix, len_prefix) == 0)
		return (ft_strcpy(substring, line + len_prefix));
	else
		return (ft_strcpy(substring, line));
}
