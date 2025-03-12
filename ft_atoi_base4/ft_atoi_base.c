
int is_valid(const char *str, int str_base)
{

    if((*str >= '0' && *str <= '9'))
    {
        return(*str - '0' < str_base);
    }
    else if((*str >= 'A' && *str <= 'F'))
    {
        return(*str - 'A' + 10 < str_base);
    }
    else if(*str >= 'a' && *str <= 'f')
    {
        return(*str - 'a' + 10 < str_base);
    }
    return(0);
}
int base(const char *str)//, int str_base)
{
    if((*str >= '0' && *str <= '9'))
    {
        return(*str - '0');
    }
    else if((*str >= 'A' && *str <= 'F'))
    {
        return(*str - 'A' + 10);
    }
    else if(*str >= 'a' && *str <= 'f')
    {
        return(*str - 'a' + 10);
    }
    return(0);
    
}

int	ft_atoi_base(const char *str, int str_base)
{
    int sign = 1;
    int res = 0;
    if(str_base < 2 || str_base > 16)
    {
        return(0);
    }
    while (*str == ' ' || (*str >= 9 && *str <= 13))
    {
        str++;
    }
    if(*str == '-' || *str == '+')
    {
        if(*str == '-')
        {
            sign = -1;
            str++;
        }
    }
    while (*str && is_valid(str, str_base))
    {
        res = res * str_base + (base(str)); //, str_base))
        str++;
    }
    return(res * sign);
}

// int main (void)
// {
//     ft_atoi_base("250F", 16);
// }