double  ft_pow(double basis, double exponent)
{
    double  res;

    if (exponent == 0)
        return (1);
    res = basis;
    while (--exponent > 0)
        res *= basis;
    return (res);
}