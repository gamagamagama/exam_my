#include<unistd.h>

void repa(char *str)
{
    while(*str)
    {
        if((*str >= 'A' && *str <= 'Z'))
        {
            int uplen = (*str - 'A') + 1;
            while(uplen > 0)
            {
                write(1, str, 1);
                uplen--;
            }

        }
        else if((*str >= 'a' && *str <= 'z'))
        {
            int lower = (*str - 'a') + 1;
            while(lower > 0)
            {
                write(1, str, 1);
                lower--;
            }
        }
        else
        {
            write(1, str, 1);
        }
        str++;
    }
}

int main (int ac, char **av)
{
    if (ac == 2)
    {
        repa(av[1]);
    }
    write(1, "\n", 1);
    return(0);
}