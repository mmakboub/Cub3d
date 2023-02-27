/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:33:27 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/27 18:26:13 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

// int main()
// {
//     char* hex_color = "F22010"; // code hexadécimal à convertir
//     char* endptr;
//     long int r = strtol(hex_color, &endptr, 16); // conversion de la composante rouge
//     long int g = strtol(endptr, &endptr, 16); // conversion de la composante verte
//     long int b = strtol(endptr, NULL, 16); // conversion de la composante bleue
//     printf("La couleur est : (%ld,%ld,%ld)", r, g, b); // affichage de la couleur en RGB
//     return 0;
// }

#include <stdio.h>
#include <string.h>

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

int main() {
    char path[] = "\nSO   ./path_to_the_south_texture\n";
    char *sub = remove_caract(path, "\n");
    printf("%sfin", sub);
    return 0;
}