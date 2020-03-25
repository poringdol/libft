int	ft_isalpha(int ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return (ch);
	return (0);
}

/*
int ft_isalpha(int ch)
{
	return (((unsigned)ch | 32) - 'a' < 26);
}
*/
