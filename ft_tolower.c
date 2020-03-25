int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	if (ch >= -128 && ch < -1)
		return (ch + 256);
	return (ch);
}