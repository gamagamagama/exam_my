#include <unistd.h>
int main(int ac, char **av)
{
    int i =0;
    if(ac == 3)
    {
        char array[256] = {0};

        while(av[2][i])
        {
            array[(unsigned char)av[2][i]] = 1;
            i++;
        }
        i = 0;
        while(av[1][i])
        {
            if(array[(unsigned char)av[1][i]] == 1)
            {
                write(1, &av[1][i], 1);
                array[(unsigned char)av[1][i]] = 2;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}