/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:35:41 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/24 17:52:47 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void memory_error(void)
{
    write(2,"error : memory wasn't allocated\n", 20);
    exit(1);
}
void parse_color(t_abtmap *game, char *cleanline)
{
    char *floor;
    char *ceilling;

    if(!ft_strncmp(cleanline, "F", 1) && game->has_f == -1)
    {
        floor = remove_prefix(cleanline, "F ");
        if(!floor)
            memory_error();
        game->floor = receive_rgb_color(game, cleanline, floor);
        if(!game->floor)
            exit(1) ;
        game->has_f = 1;
    }
    else  if(!ft_strncmp(cleanline, "C", 1) && game->has_c == -1)
    {
        ceilling = remove_prefix(cleanline, "C ");
        if(!ceilling)
            memory_error();
        game->ceilling = receive_rgb_color(game, cleanline, ceilling);
        if(!game->ceilling)
            exit(1);
        game->has_c = 1;
    }
}

int receive_rgb_color(t_abtmap *game, char *cleanline, char *color)
{
    char **rgbclr;
    int decrgb;
    
    int i = 0;
    rgbclr = ft_split(color, ',');
    if(!rgbclr)
        memory_error();
    while(rgbclr[i])
        i++;
    if (i != 3)
    {
        free(rgbclr);
		printf("error: there are more than 3 numbers!! \n");
        exit(0);
    }   
    decrgb = rgb_converter(game, rgbclr);
    if(!decrgb)
        return(write(2,"Error : RGB colors are not available \n", 20), 0);
    return(decrgb);
}

int	isalldigits(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}


int rgb_converter(t_abtmap *game, char **rgbclr)
{
    int i;
    int color;

    i = 0;
    while(rgbclr[i])
    {
        if(!isalldigits(rgbclr[i]))
            return(0);
        i++;            
    }
    while(rgbclr[i])
    {
        if(ft_atoi(rgbclr[i]) <= 0 || ft_atoi(rgbclr[i]) >= 255)
            return(0);
        i++;
    }
    color = ft_atoi(rgbclr[0]) << 16 | ft_atoi(rgbclr[1]) << 8 | ft_atoi(rgbclr[2]);
    return(color);
}