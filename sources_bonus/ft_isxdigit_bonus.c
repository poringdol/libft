int	ft_isxdigit(int ch)
{
	if ((ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f') || (ch >= '0' && ch <= '9'))
		return (ch);
	return (0);
}
