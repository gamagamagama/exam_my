#include <stdlib.h>
#include <stdio.h>

void pgcd(int first, int sec)
{
    int i = first;

    while(i > 0)
    {
        if(first % i == 0 && sec % i == 0)
        {
            printf("%d", i);
            break;
        }
        i--;
    }
}


int main(int ac, char **av)
{

    int frst;
    int sec;
    if(ac == 3)
    {
        frst = atoi(av[1]);
        sec = atoi(av[2]);
        pgcd(frst, sec);
    }
    printf("\n");
}