/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:26:45 by egomez-a          #+#    #+#             */
/*   Updated: 2021/11/05 12:57:16 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Reserva con malloc(3) y devuelve un array de strings obtenido al separar */
/* ’s’ con el caracter ’c’ como delimitador. El array debe terminar en NULL. */

static int	ft_countwords(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	if (!s || s[0] == 0)
		return (0);
	i = 0;
	cntr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}

static char	**ft_malloc(char const *s, char c)
{
	int			len;
	char		**tab;

	len = ft_countwords(s, c);
	tab = malloc(sizeof(*tab) * (len + 1));
	if (tab == 0)
		return (0);
	return (tab);
	if (!(tab))
		return (0);
}

static int	ft_wordcountnext(char const *s, char c, int i)
{
	int	cntr;

	cntr = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		cntr++;
		i++;
	}
	return (cntr);
}

static char	**ft_free(char **tab, int i)
{
	int	j;

	j = 0;
	while (j < i && tab[j] != 0)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		j;
	char	**tab;

	i = -1;
	start = 0;
	if (s == 0)
		return (0);
	tab = ft_malloc(s, c);
	while (++i < ft_countwords(s, c))
	{
		j = 0;
		tab[i] = malloc(ft_wordcountnext(s, c, start) + 1);
		if (!(tab[i]))
			return (ft_free(tab, i));
		while (s[start] != '\0' && s[start] == c)
			start++;
		while (s[start] != '\0' && s[start] != c)
			tab[i][j++] = s[start++];
		tab[i][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
