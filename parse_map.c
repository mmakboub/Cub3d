/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:33:48 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/25 23:40:27 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_n(char **map, int i, int j)
{
	if (i == 0 || map[i - 1][j] == ' ')
		return (0);
	else if (ft_strlen(map[i - 1]) <= j + 1)
		return (0);
	return (1);
}

int	valid_e(char **map, int i, int j)
{
	if (map[i][j] == '\n' || map[i][j] == '\0' || map[i][j] == ' ')
		return (0);
	return (1);
}

int	valid_s(char **map, int i, int j, t_abtmap *game)
{
	int	lastline;

	lastline = game->maplines - game->lineindex - 1;
	if (i == lastline)
		return (0);
	else if (map[i + 1][j] == '\0' || map[i + 1][j] == ' ')
		return (0);
	else if (ft_strlen(map[i + 1]) <= j)
		return (0);
	return (1);
}

int	valid_w(char **map, int i, int j)
{
	if (j == 0)
		return (0);
	if (map[i][j - 1] == ' ')
		return (0);
	else
		return (1);
}

int	check_valid_map(int i, int j, char **map, t_abtmap *game, int *counter)
{
	if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || \
game->map[i][j] == 'E' || game->map[i][j] == 'W')
		(*counter)++;
	if (*counter == 1 || game->map[i][j] == '0')
	{
		if (!valid_n(map, i, j) || !valid_e(map, i, j) || !valid_s(map, i, j, \
game) || !valid_w(map, i, j))
			return (printf("map is invalide\n"), exit(1), 0);
	}
	else if (*counter > 1)
		return (printf("there is more than 1player \n"), exit(1), 0);
	return (1);
}

int	checkmap(t_abtmap *game)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' || \
game->map[i][j] == 'E' || game->map[i][j] == 'W' || game->map[i][j] == '0')
			{
				if (!check_valid_map(i, j, game->map, game, &counter))
					return (0);
			}
			else if (game->map[i][j] != '1' && game->map[i][j] != ' ' && \
			game->map[i][j] != '\n')
				return (printf("Error: invalid map!!\n"), 0);
			j++;
		}
		i++;
	}
	if (counter == 0)
		return (printf("map is invalide it should contain 1 player"), exit(1),
			0);
	return (1);
}

int	parse_map(t_abtmap *game, char *first_line, int fd)
{
	int		i;
	char	*line;

	i = 1;
	game->map = (char **)malloc((game->maplines - game->lineindex + 1) * \
	sizeof(char *));
	if (!(game->map))
		return (0);
	game->map[0] = first_line;
	line = get_next_line(fd);
	while (i < game->maplines - game->lineindex)
	{
		game->map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	checkmap(game);
	close(fd);
	return (1);
}
