#include<unistd.h>

char *decap(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        i++;
    }
    return(str);
}
int str_len(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return(i);
}
int ch(char *str)
{
    return((*str >= 'a' && *str <= 'z')? 1 : 0);
}
int deli(char *str)
{
    return(((*str == ' ') || (*str >= 9 && *str <= 13))? 1 : 0);
}
char *cap(char *str, int len)
{
    int word = 1;
    while (str[len])
    {
        if(ch(&str[len]) && word)
        {
            str[len] -= 32;
        }
        word = deli(&str[len]);
        len--;
    }
    return(str);
}
void capita(char *str)
{
    int len = str_len(str) - 1;
    decap(str);
    cap(str, len);
    while(*str)
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    int i = 1;
    int j = (ac - 1);
    if(ac > 1)
    {
        while(i <= j)
        {
            capita(av[i]);
            i++;
        }
    }
    else
    {
        write(1, "\n", 1);   
    }
}