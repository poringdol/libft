// int	ft_isdigit(int ch)
// {
// 	if (ch >= '0' && ch <= '9')
// 		return (ch);
// 	return (0);
// }

int ft_isdigit(int ch)
{
	return ((unsigned)ch - '0' < 10);
}