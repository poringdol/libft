int ft_atoi(const char *str)
{
    unsigned int    i;
    long            nb;
    long            nb_prev;
    int             sign;

    i = 0;
    nb = 0;
    sign = 1;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)       /* skip spaces at the beginning */
        i++;
    if (str[i] == '-')
        sign = -sign;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb_prev = nb;
        nb = nb * 10 + str[i] - '0';
        i++;
        if (nb_prev > nb)
            return (sign == 1 ? -1 : 0);
    }
    nb *= sign;
    return ((int)nb);
}