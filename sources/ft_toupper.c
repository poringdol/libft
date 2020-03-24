int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	if (ch >= -128 && ch < -1)
		return (ch + 256);
	return (ch);
}

// static int	ft_islower(int ch)
// {
// 	return ((unsigned)ch - 'a' < 26);
// }

// int			ft_toupper(int ch)
// {
// 	if (ft_islower(ch))
// 		return (ch & 0x5f);
// 	return ch;
// }