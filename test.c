/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:33:27 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/22 00:18:34 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

char *remove_prefix(char* str, char* prefix) {
    char *src = strdup("");
    size_t len_prefix = strlen(prefix);
    if (strncmp(str, prefix, len_prefix) == 0) {
       return (strcpy(src, str + len_prefix));
    }
    else {
        return(strcpy(src, str));
    }
}

int main() {
    char path[] = "SO   ./path_to_the_south_texture";
    char prefix[] = "SO  ";
    char result[100];
    char *sub = remove_prefix(path, prefix);
    printf("%s\n", sub);
    return 0;
}