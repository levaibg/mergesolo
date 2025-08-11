/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:21:02 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/11 16:26:24 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
// # include "../../mlx_here/minilibx-linux/mlx.h"

# define FLOOR			'0'
# define WALL			'1'
# define ITEM			'2'
# define NORTH_CAMERA	'N'
# define EAST_CAMERA	'E'
# define WEST_CAMERA	'W'
# define SOUTH_CAMERA	'S'

# define ESC	65307
# define W		119
# define A		97
# define S		115
# define D		100

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"

# define FLOOR			'0'
# define WALL			'1'
# define ITEM			'2'
# define NORTH_CAMERA	'N'
# define EAST_CAMERA	'E'
# define WEST_CAMERA	'W'
# define SOUTH_CAMERA	'S'

# define ESC		65307
# define W			119
# define A			97
# define S			115
# define D			100
# define G			103

# define NORTH		0
# define SOUTH		1
# define WEST 		2
# define EAST 		3

# define PI			3.14159265359
# define S_SQUARE	64

# define RIGHT		65363
# define LEFT		65361

# define WIDTH		1280
# define HEIGHT		720
# define DD_MOD		0

// typedef struct s_data
// {
// 	char	**map;
// 	char	**truemap;
// 	char	**map2;
// 	char	**map3;
// 	int		line_len;
// 	int		true_map_len;
// 	int		floor_color;
// 	int		roof_color;
// 	char	*file_north;
// 	char	*file_south;
// 	char	*file_east;
// 	char	*file_west;
// 	int		file_size;
// 	int		player_y;
// 	int		player_x;
// }	t_data;

typedef struct s_pixel
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
} t_pixel;

typedef struct s_tex
{
	void			*textures[4];
	int				tex_height;
	int				tex_width;
	void			*img;
	char			*addr[4];
	t_pixel			*pixels[4];
	int				bpp;
	int				line_len;
	int				endian;
	int				y;
	int				tex_x;
	int				tex_y;
	int				color;
	double			step;
	double			tex_pos;
	int				wall_height;
}	t_tex;

typedef struct s_image
{
	void			*img;
	char			*addr;
	t_pixel			*pixels;
	int				bit_pxl;
	int				line_len;
	int				endian;
}	t_image;

typedef struct s_player
{
	double			angle;
	double			pos_x;
	double			pos_y;
	double			cos_angle;
	double			sin_angle;
	double			angle_speed;
	int				speed;
	struct s_image	*img;
}	t_player;
typedef struct s_data
{
	int				minimap_w;
	int				step_x;
	int				step_y;
	int				minimap_h;
	int				start_y;
	int				end;
	double			distance;
	void			*mlx;
	void			*win;
	int				frame;
	bool			front;
	bool			back;
	bool			left;
	bool			right;
	bool			camera_left;
	bool			camera_right;
	// char			**mapo;
	int				side;
	double			ray_dir_x;
	double			ray_dir_y;
	double			wall_x;
	double			wall_y;
	int				wall_dir;
	double			map_pos_y;
	double			map_pos_x;
	struct s_image	*img;
	struct s_player	*player;
	struct s_tex	*tex;
	char	**map;
	char	**truemap;
	char	**map2;
	char	**map3;
	int		line_len;
	int		true_map_len;
	int		floor_color;
	int		roof_color;
	char	*file_north;
	char	*file_south;
	char	*file_east;
	char	*file_west;
	int		file_size;
	int		player_y;
	int		player_x;
}	t_data;

///////////////////////////////////__EXEC__////////////////////////////////////

// mlx_util.c
void	init_mlx(t_data *data, t_image *image);
void	mlx_pxl(t_image *img, int x, int y, int color);
void	mlx_pxl_pixel(t_image *img, int x, int y, t_pixel color);
void	mlx_draw(int i, int j, t_image *img);

// utils.c
void	init_player(t_player *player, t_data *data, char st);
void	init_var2(t_data *data, t_image *image, t_player *player);
void	ft_freexit(t_data *data, char *msg);
int		ft_close(t_data *data);

// move.c
void	player_intructs(t_data *data, t_player *player);
void	player_camera(t_data *data, t_player *player);
void	player_camera_2(t_data *data, t_player *player);

void	draw_player(int x, int y, t_data *data);
void	draw_player2(int x, int y, t_data *data);
void	draw_player3(int x, int y, t_data *data);
void	draw_player4(int x, int y, t_data *data);
int		draw_player_loop(t_data *data);

// utils2.c
int		press(int keycode, t_data *data);
int		release(int keycode, t_data *data);

// draw.c
int		draw_player_loop(t_data *data);
void	clear_img(t_data *data);
void	map(t_data *data);
void	draw_map(t_data *data);

// ray.c
bool	line_to_wall(double px, double py, t_data *data);
double	sqr(double a);
double	squirt(double x, double y, double x1, double x2);
void	ray(t_data *data, int i, int size, double p_x, double p_y);

// minimap.c
void	draw_ray(t_data *data, double ray_dir_x, double ray_dir_y, int x);
void	draw_minimap(t_data *data);
void	draw_minimap_end(t_data *data, int x, int y);

// texture.c
int		get_wall_dir(t_data *data);
void	load_textures(t_tex *tex, t_data *data);

void	draw_textured_wall(t_data *d, int x, int wall_h);
void	draw_texture_column(t_data *data, int x, int start_y, int end_y, int wall_dir, double p);
int		get_tex_color(t_tex *tex, int dir, int x, int y);



/* map */
void	assign_map(t_data *data);
void	map_alloc(t_data *data);
void	check_player_count(t_data *data);
void	check_walls(t_data *data);
int		is_replace_char(t_data *data, int i, int j);
int		is_map_char(t_data *data, int i, int j);

/* parsing */
void	map_name(char *map);
int		parsing(t_data *data, int ac, char **av);

/* utils */
void	init_var(t_data *data);
void	print_exit(char *str);
int		ft_strlen(char *str);
char	*ft_dup(char *s1);
int		ft_strcmp_pos(char *s1, char *s2);
char	*ft_sub(char *s, int start, int len);
void	free_all(t_data *data);
void	free_exit(t_data *data, char *str);
void	free_map_exit(t_data *data, char *str);
int		ft_is_ws(int i);
char	**ft_spliter(char *s, char c);
int		ft_atoi(char *str);

/* walls utils */
int		check_arg(char *arg, char f, char s);
int		check_ws(char *arg, int i);

/* floor utils */
void	floor_color_arg(t_data *data, char *arg);
int		ft_isdigit(int c);
int		ft_strcmp_clor(char *s1, char *s2);
int		find_char(char *str, char c);
void	free_tab(char **tab);
int		check_red(t_data *data, char *red);
int		check_green(t_data *data, char *green);
int		check_blue(t_data *data, char *blue);
int		rgb_to_hex(int r, int g, int b);
void	check_is_num(t_data *data, char *red, char *green, char *blue);
void	free_rgb(t_data *data, char *red, char *green, char *blue);

/* roof color */
void	roof_color_arg(t_data *data, char *arg);
void	free_colors(t_data *data, char **color);
void	check_xpm(t_data *data);

/* files & colors check */
void	wall_files_check(t_data *data);
void	color_check(t_data *data);

/* gnl */
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strncpy(char *s1, char *s2, char c);
char	*ft_strcpy(char *a, char *b);
char	*ft_strchr(const char *s, int c);
char	*ft_split(char *src, char car);
char	*ft_ligne(int fd, char *ligne, char *buffer);

/* misc */
void	print_map(char **map);

/* surround check */
void	floodfill(t_data *data);

#endif
