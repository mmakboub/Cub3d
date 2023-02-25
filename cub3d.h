/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:01:19 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/25 23:28:18 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// #define MAPWIDTH 22
// #define MAPHEIGHT 17
// #define TILE_SIZE 30
// #define SCREENWIDTH 1500
// #define SCREENHEIGHT 940
// #define PI 3.14159265
// #define VIEW_ANGLE 60 * PI / 180
// #define MINI_MAP_FACTOR 0.2
# include "gnl/get_next_line.h"
# include "libft_zack/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img_data;

typedef struct s_cordinates
{
	double			x;
	double			y;
}					t_cordinates;

typedef struct s_player_data
{
	t_cordinates	position;
	int				radius;
	int				movespeed;
	double			viewangle;
	double			rotationspeed;
	int				movesleft_or_right;
	int				turndirection;
	int				walkdirection;
	t_img_data		*img;
	void			*mlx;
	void			*mlx_win;
}					t_player_data;

typedef enum keys
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	TURN_LEFT = 123,
	TURN_RIGHT = 124,
}					t_keys;

typedef struct s_ray
{
	double			angle;
	double			distancetowall;
	int				isfacingdown;
	int				isfacingup;
	int				isfacingleft;
	int				isfacingright;
	t_cordinates	horzwallhit;
	t_cordinates	vertwallhit;
	bool			wallhitisvert;
}					t_ray;

typedef struct s_abtmap
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			**map;
	int				has_no;
	int				has_so;
	int				has_we;
	int				has_ea;
	int				maplines;
	int				lenghtlines;
	int				has_f;
	int				has_c;
	int				floor;
	int				ceilling;
	int				lineindex;

}					t_abtmap;

char				*remove_caract(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_check_cub(char *filename);
int					countline(char *file);
int					ft_reading_maps(t_abtmap *jeu, char *file);
char				**remplir_tableau(void);
void				initializer(t_abtmap *game);
void				free_tab(char **tab, int size);
int					check_intern_map(char *clean_ptr, t_abtmap *game);
void				parse_direction(t_abtmap *game, char *line);
void				ea_direct(t_abtmap *game, char *line);
void				no_direct(t_abtmap *game, char *line);
void				we_direct(t_abtmap *game, char *line);
void				so_direct(t_abtmap *game, char *line);
char				*ft_strcpy(char *dest, char *src);
char				*remove_prefix(char *line, char *prefix);
void				memory_error(void);
void				parse_color(t_abtmap *game, char *cleanline);
int					receive_rgb_color(t_abtmap *game, char *cleanline,
						char *color);
int					isalldigits(const char *s);
int					rgb_converter(t_abtmap *game, char **rgbclr);
int					parse_map(t_abtmap *game, char *first_line, int fd);
int					valid_n(char **map, int i, int j);
int					valid_e(char **map, int i, int j);
int					valid_s(char **map, int i, int j, t_abtmap *game);
int					valid_w(char **map, int i, int j);
int					check_valid_map(int i, int j, char **map, t_abtmap *game,
						int *counter);
int					checkmap(t_abtmap *game);

#endif