#include "libft.h"

int	ft_isalnum(int ch)
{
	if (ft_isdigit(ch) || ft_isalpha(ch))
		return (8);
	return (0);
}
