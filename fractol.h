#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
# include "/home/melmarti/42_projects/fractol/mlx/mlx.h"

#define WIDHT 800
#define HEIGHT 800
#define BLACK 0x000000          // Noir
#define DARK_GRAY1 0x111111      // Gris foncé 1
#define DARK_GRAY2 0x222222      // Gris foncé 2
#define DARK_GRAY3 0x333333      // Gris foncé 3
#define GRAY1 0x444444           // Gris 1
#define GRAY2 0x555555           // Gris 2
#define GRAY3 0x666666           // Gris 3
#define LIGHT_GRAY1 0x777777     // Gris clair 1
#define LIGHT_GRAY2 0x888888     // Gris clair 2
#define LIGHT_GRAY3 0x999999     // Gris clair 3
#define GOLD1 0xAA8800           // Doré 1
#define GOLD2 0xBB9900           // Doré 2
#define GOLD3 0xCCAA00           // Doré 3
#define GOLD4 0xDDBB00           // Doré 4
#define GOLD5 0xEECC00           // Doré 5
#define GOLD 0xFFD700            // Doré

typedef struct s_img
{
	void *img_ptr;
	char *pixel_ptr; // pointing to 1 byte pixel pointer
	int bpp;
	int endian;
	int line_len;
} 			t_img;

typedef struct s_fractal
{
	char *name;
	void *mlx;
	void *mlx_connexion;
	void *mlx_window;
	t_img img;
} t_fractal;

typedef struct s_complex
{
	int x;
	int y;
}	t_complex;

int ft_strcmp(char *s1, char *s2);
double ft_atod(char *s);
int	ft_error(void);
void ft_memerror(void);
void ft_fractal_init(t_fractal *fractal);
void ft_fractal_render(t_fractal *fractal);

#endif