int     ft_isspace(int ch)
{
	if ((ch >= 9 && ch <= 13) || ch == 32)
		return (ch);
	return (0);
}