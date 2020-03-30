int	ft_isgraph(int ch)
{
	if (ch > 32 && ch <= 126)
		return (ch);
	return (0);
}
