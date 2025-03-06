#include <stdio.h>

int ft_atoi(const char *str)
{
    int nmbr = 0;
    int sign = 1;
    while(*str == '\n' || *str == '\t' || *str == '\v' || *str == '\r' || *str == ' ' )
    { 

        str++;
    }
    if(*str ==  '+' || *str == '-')
    {
        if(*str == '-')
        {
            sign *= - 1;
        }
        str++;
    }
    while(*str >= '0' && *str <= '9')
    {
        nmbr = nmbr *  10 + (*str - '0');
        str++;
    }
    return(nmbr * sign);

}

// int main (int ac, char **av)
// {
//     if(ac == 2)
//     {
//         int num = ft_atoi(av[1]);
//         printf("%d", num);
//     }
// }