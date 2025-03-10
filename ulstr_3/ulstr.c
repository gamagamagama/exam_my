#include<unistd.h>
#include<stdio.h>
int main (int ac, char **av)
{
   
    if(ac == 2)
    {
        char *str = av[1];
        while(*str)
        {
            int upper = (*str >= 'A' && *str <= 'Z');
            int lower = (*str >= 'a' && *str <= 'z');
            if(lower)
            {
                *str -= 32;
            }
            else if(upper)
            {
                *str += 32;
            }
            write(1, str, 1);
            str++;
        }
    }
    write(1, "\n", 1);
}