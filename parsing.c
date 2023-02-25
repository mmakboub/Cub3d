/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:00:35 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/25 17:02:53 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	ft_check_cub(char *filename)
{
	int	len;
	len = ft_strlen(filename);
	if (filename[len - 4] != '.' || filename[len - 3] != 'c'
		|| filename[len - 2] != 'u' || filename[len - 1] != 'b')
	{
		write(2, "this file's name needs to be ended by .ber\n", 24);
		exit(1);
	}
}

int countline(char *file)
{
	char	*line;
	int		fd;
	int		count;
	char *tmp;

	count = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			close(fd);
			break ;
		}
		tmp = remove_caract(line, " \n");
		if (ft_strlen(tmp))
			count++;
		free(tmp);
		free(line);
	}
	return (count);
}




void initializer(t_abtmap *game)
{
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->map = NULL;
	game->ea = NULL;
	game->map = NULL;
	game->maplines = 0;
	game->lenghtlines = 0;
	game->has_ea = -1;
	game->has_no = -1;
	game->has_we = -1;
	game->has_so = -1;
	game->has_c = -1;
	game->has_f = -1;
	game->floor = 0;
	game->ceilling = 0;
}

char	**remplir_tableau(void) 
{
    char** tableau = malloc(3 * sizeof(char*));
    tableau[0] = ft_strdup("F ");
    tableau[1] = ft_strdup("C ");
    tableau[2] = ft_strdup("1");
    return (tableau);
}

void free_tab(char **tab, int size) 
{
	int i;
	i = 0;
	while(i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int check_intern_map(char *clean_ptr, t_abtmap *game)
{
	int j;
	char **tab;
	int i = 0;

	while(clean_ptr[i++])
	{
		if(game->lenghtlines > 3)
		{
			if (ft_strnstr(clean_ptr, "NO ", 3) || ft_strnstr(clean_ptr, "SO ", 3) ||
			ft_strnstr(clean_ptr, "WE ", 3) || ft_strnstr(clean_ptr, "EA ", 3))
				return (1);
		}
		j = 0;
		tab = remplir_tableau();
		while (j < 3) 
		{
    		if (ft_strncmp(clean_ptr, tab[j], ft_strlen(tab[j])) == 0) 
			{
        		if (j == 2)
        		    return (free_tab(tab, 3), 2);
				else
					return (free_tab(tab, 3), 3);
    		}
    		j++;
		}
		free_tab(tab, 3);
	}
	return(printf("Error: invalid map's informations!!\n"), 0);
}



void check_retvalue(int retvalue, char *clean_ptr, t_abtmap *game, char *ptr)
{
	if (retvalue == 1)
		parse_direction(game, clean_ptr);
	else if (retvalue == 3)
		parse_color(game, clean_ptr);
	else
		exit(0);
}

int ft_reading_maps(t_abtmap *game, char *file)
{
	char	*ptr;
	char	*clean_ptr;
	int fd;
	int retvalue;
	fd = open(file, O_RDONLY);
	if(fd < 0)
		write(2, "there is a probleme in operning file", 48);
	ptr = get_next_line(fd);
	game->lineindex = 0;
	if (!ptr)
		return(0);
	game->maplines = countline(file);	
	while(ptr)
	{
		clean_ptr = remove_caract(ptr, " \n");
		if(!clean_ptr)
			return(0);
		game->lenghtlines = ft_strlen(clean_ptr);
			int i = 0;
		if(game->lenghtlines == 0)
		{
			free(clean_ptr);
			ptr = get_next_line(fd);
			continue;
		}
		retvalue = check_intern_map(clean_ptr, game);
		if (retvalue == 2)
			break;
		else
			check_retvalue(retvalue, clean_ptr, game, ptr);
		free(ptr);
		ptr = get_next_line(fd);
		game->lineindex++;

	}
	if(game->has_c != 1 || game->has_we != 1 || game->has_f != 1 || game->has_no != 1 || game->has_so != 1 || game->has_we != 1)
		return(printf("Error : invalid map"), 0);
	parse_map(game, ptr, fd);
	return(1);
}

int main(int ac, char **av)
{
	t_abtmap	game;
	char *file;
	int i;
	if(ac != 2)
		write(2, "error in puting args", 20);
	else
	{
		file = av[1];
		initializer(&game);
		int res;
		ft_check_cub(file);
		res = ft_reading_maps(&game, av[1]);
		if(res)
		{
			i = 0;
			printf("NO = %s\n", game.no);
			printf("SO = %s\n", game.so);
			printf("EA = %s\n", game.ea);
			printf("we = %s\n", game.we);
			printf("floor = %d\n", game.floor);
			printf("ceilling = %d\n", game.ceilling);
			while(game.map[i])
				printf("%s", game.map[i++]);
		}
		else
			puts("ko");
	}
	return(1);
}