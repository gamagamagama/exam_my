#include<stdio.h>
#include<unistd.h>

int deli(char *str)
{
    return((*str == ' ' || (*str >= 9 && *str <= 13))? 1 : 0); 
}
int ch(char *str)
{
    return(((*str >= 'a' && *str <= 'z')) ? 1 : 0);
}
char *decap(char *str)
{
    int i =0;
    while (str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        i++;
    }
    return(str);
}
char *cap(char *str)
{
    int i = 0;
    int word = 1;
    while (str[i])
    {
       if(word && ch(&str[i]))
       {
            str[i] -=32;
       }
       word = deli(&str[i]);
       i++;
    }
    return(str);
}
void capit(char *str)
{
    decap(str);
    cap(str);
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if(ac > 1)
    {
        int i = 1;
        int j = (ac - 1);
        while(i <= j)
        {

            capit(av[i]);
            i++;

        }
    }
    else
    {
        write(1, "\n", 1);
    }
}