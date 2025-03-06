 #include <stdlib.h>
#include <stdio.h>

int do_op(int first, int third, char *sign)
{
    int result=0;
    if(*sign == 43)
        result = (first + third);
    else if(*sign == 45)
        result = (first - third);
    else if(*sign == 42)
        result = (first * third);
   else if(*sign == 47)
        result = (first / third);
    else if(*sign == 37)
        result = (first % third);
    return(result);
        
}

int main(int ac, char **av)
{
    if(ac == 4)
    {
        int first = atoi(av[1]);
        int third = atoi(av[3]);
        int result;
        char *sign = av[2];
        result = do_op(first, third, sign);
        printf("%d", result);
    }
    printf("\n");
    return(0);
}