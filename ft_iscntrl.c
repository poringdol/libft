int     ft_iscntrl(int ch)
{
	if ((ch >= 0 && ch <= 31) || ch == 127)
		return (1);
	return (0);
}