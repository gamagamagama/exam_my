#include <unistd.h>
#include <stdio.h>
void put_nmbr(int num);


int is_prime(int num)
{
   for(int i = 2; i * i <= num; i++)
   {
        if(num % i == 0)
            return(0);
   }
   return(1);
}
void prime_sum(int num)
{
    int i = 2;
    int sum = 0;
    while (i <= num)
    {
        if(is_prime(i))
        {
            sum = sum + i;
        }
        i++;
    }
    put_nmbr(sum);
}

void put_nmbr(int num)
{
    char digit;
    if (num > 9)
    {
        put_nmbr(num / 10);
    }
    digit = num % 10 + '0';
    write(1, &digit, 1);

}

int is_num(char *str)
{
    int i = 0;

    if (!str[i]) return 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
int ato(char *str)
{
    int num = 0;
    if(*str == '-')
        return(0);
    while (*str && (is_num(str)))
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return(num);
}

int main (int ac, char **av)
{
    if(ac == 2 && is_num(av[1]))
    {
        int num = ato(av[1]);
        prime_sum(num);
        
    }
    else
    {
        put_nmbr(0);
    }
    write(1, "\n", 1);
}