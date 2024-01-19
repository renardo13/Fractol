#include "fractol.h"

double ft_atod(char *s)
{
    int i;
    int sign;
    double nbr;
    double fraction;

    sign = 1;
    nbr = 0.0; 
    fraction = 0.1;
    i = 0;

    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9' && s[i] != '.')
        nbr = nbr * 10 + (s[i++] - '0');
    i++;
        while (s[i] >= '0' && s[i] <= '9')
        {
            nbr = nbr + (fraction * (s[i++] - '0'));
            fraction /= 10;
        }
    return (nbr * sign);
}
