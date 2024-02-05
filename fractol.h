/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melmarti <melmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:49:09 by melmarti          #+#    #+#             */
/*   Updated: 2024/02/05 19:21:01 by melmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/home/melmarti/42_projects/fractol/mlx/mlx.h"
// change the path if you
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// want to launch the program

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000 // Noir
# define WHITE 0xFFFFFF
# define DARK_GRAY1 0x111111  // Gris foncé 1
# define DARK_GRAY2 0x222222  // Gris foncé 2
# define DARK_GRAY3 0x333333  // Gris foncé 3
# define GRAY1 0x444444       // Gris 1
# define GRAY2 0x555555       // Gris 2
# define GRAY3 0x666666       // Gris 3
# define LIGHT_GRAY1 0x777777 // Gris clair 1
# define LIGHT_GRAY2 0x888888 // Gris clair 2
# define LIGHT_GRAY3 0x999999 // Gris clair 3
# define GOLD1 0xAA8800       // Doré 1
# define GOLD2 0xBB9900       // Doré 2
# define GOLD3 0xCCAA00       // Doré 3
# define GOLD4 0xDDBB00       // Doré 4
# define GOLD5 0xEECC00       // Doré 5
# define GOLD 0xFFD700        // Doré
# define PSYCHEDELIC5 0x800080

typedef struct s_img
{
	void	*img_ptr;
	char *pixel_ptr; // pointing to 1 byte pixel pointer
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*mlx_connection;
	void	*mlx_window;
	int		iter;
	double	julia_x;
	double	julia_y;
	double	shift_y;
	double	shift_x;
	double	zoom;
	t_img	img;
}			t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

// utils
double		ft_atod(char *s);
int			ft_strcmp(char *s1, char *s2);
int			ft_error(void);
void		ft_memerror(void);

// init
void		ft_fractal_init(t_fractal *fractal);
void		ft_fractal_data(t_fractal *fractal, char *real, char *im);
double		ft_scale(double unscaled_num, double new_min, double new_max,
				double old_max);
void		ft_color_pxl(double x, double y, t_fractal *fractal);
void		ft_fractal_render(t_fractal *fractal);
void		ft_events_init(t_fractal *fractal);
int			ft_key_handler(int keysym, t_fractal *fractal);
int			ft_close_handler(t_fractal *fractal);
t_complex	ft_square_complex(t_complex z);
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
int			ft_abs(int nb);
t_complex	ft_remarkable(t_complex z);
int			ft_mouse_handler(int button, int x, int y, t_fractal *fractal);
int			ft_track_mouse(int x, int y, t_fractal *fractal);

#endif