int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	if (ch >= -128 && ch < -1)
		return (ch + 256);
	return (ch);
}