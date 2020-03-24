int	ft_isascii(int ch)
{
	if (ch >= 0 && ch <= 127)
		return (1);
	return (0);
}

// int ft_isascii(int c)
// {
// 	return !(c & ~0x7f);
// }