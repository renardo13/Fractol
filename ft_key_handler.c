#include "fractol.h"

// we use keysym to be sure that the right code is 
// used because the keycode can be different according to keyboards

int ft_key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);	
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);	
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);	
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);	
	if(keysym == XK_plus)
		fractal->iter += 10;
	if(keysym == XK_minus)
		 fractal->iter -= 10;
	ft_fractal_render(fractal);
	return 0;
}
