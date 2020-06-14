#include "libft.h"

static double	get_float(char *str)
{
	int		i;
	float	flt;

	flt = 0;
	i = ft_strlen(str);
	while (i--)
		flt = (flt + (str[i] - '0')) / 10;
	return (flt);
}

double				ft_atof(char *str)
{
	double	nb;
	double	sign;

	nb = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	if (*str == '.')
	{
        double f = get_float(++str);
        nb += f;
    }
	nb *= sign;
	return ((float)nb);
}