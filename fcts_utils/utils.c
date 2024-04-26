/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:56:28 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/05 15:56:52 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	*ft_free_str_tab(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (0);
}

int	ft_count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*ft_next_word(char **s, char c)
{
	char	*start;
	char	*word;
	int		len;

	while (**s == c)
		(*s)++;
	start = *s;
	len = 0;
	while (**s && **s != c)
	{
		(*s)++;
		len++;
	}
	word = ft_calloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	(*s) = start;
	len = 0;
	while (**s && **s != c)
		word[len++] = *((*s)++);
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**tab;
	char	**tab_start;
	char	*str;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	tab = ft_calloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab_start = tab;
	str = (char *)s;
	while (words--)
	{
		*tab = ft_next_word(&str, c);
		if (!(*tab))
			return (ft_free_str_tab(tab_start));
		tab++;
	}
	*tab = NULL;
	return (tab_start);
}
