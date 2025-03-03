#include <stdio.h>
#include <stdlib.h>
int is_prime(int n)
{
    int i = 2;
    while(i < n)
    {
        if(n % i == 0)
        {
            return(0);
        }
        ++i;
    }
    return(1);
}

void fprime(int n)
{
    int factor = 2;
    int flag = 1;
    if(n == 1)
        printf("1");
    while(factor <= n)
    {
        if(n % factor == 0 && is_prime(factor))
        {
            if(flag == 1)
            {
                printf("%d", factor);
                flag = 0;
            }
            else
            {
                printf("*%d", factor);
            }
            n = n / factor;
        }
        else
        {
            factor++;
        }

    }

}

int main(int ac, char **av)
{
    
    if(ac == 2)
    {
        char *str = av[1];
        int n = atoi(str);
        fprime(n);
    }
     printf("\n");
    return(0);
}