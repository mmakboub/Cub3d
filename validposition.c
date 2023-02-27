/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validposition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:08:10 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/27 19:47:14 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_n(char **map, size_t i, size_t j)
{
	if (i == 0 || map[i - 1][j] == ' ')
		return (0);
	else if (ft_strlen(map[i - 1]) <= j)
	{
		return (0);
	}
	return (1);
}

int	valid_e(char **map, size_t i, size_t j)
{
	if (map[i][j] == '\0' || map[i][j] == ' ')
		return (0);
	return (1);
}

int	valid_s(char **map, size_t i, size_t j, t_abtmap *game)
{
	int	lastline;
	lastline = game->maplines - game->lineindex - 1;
	if ((int)i == lastline)
		return (0);
	else if (map[i + 1][j] == '\0' || map[i + 1][j] == ' ')
		return (0);
	else if (ft_strlen(map[i + 1]) <= j)
		return (0);
	return (1);
}

int	valid_w(char **map, size_t i, size_t j)
{
	if (j == 0)
		return (0);
	if (map[i][j - 1] == ' ')
		return (0);
	else
		return (1);
}
