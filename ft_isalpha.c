int	ft_isalpha(int ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return (ch);
	return (0);
}
