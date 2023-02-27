/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utis2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:16:13 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/27 20:30:40 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int numberofgamma(char *pathcolor)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while(pathcolor[i])
    {
        if(pathcolor[i] == ',')
            j++;
        i++;
    }
    return(j);
}

int checkgamma(char *pathcolor)
{
    int nbrofgamma;
    nbrofgamma = numberofgamma(pathcolor);
    if(nbrofgamma == 2)
        return(1);
    return(0);
}