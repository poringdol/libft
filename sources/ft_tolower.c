int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	if (ch >= -128 && ch < -1)
		return (ch + 256);
	return (ch);
}

// static int	ft_isupper(int ch)
// {
// 	return ((unsigned)ch - 'A' < 26);
// }

// int			ft_tolower(int ch)
// {
// 	if (ft_isupper(ch))
// 		return (ch | 32);
// 	return ch;
// }