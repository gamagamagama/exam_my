#include<unistd.h>
int deli(char *str)
{
    return(*str == ' ' || (*str >= 9 && *str <= 13)? 1 : 0);
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

void rev(char *str)
{
    int i = str_len(str) - 1;
    int word = 0;
    int start = 0;
    while(i >= 0)
    {
        while(i >= 0 && deli(&str[i]))
        {
            i--;
        }
        if(i < 0)
        {
            break;
        }
        start = i;
        while(i >= 0 && !deli(&str[i]))
        {
            i--;
        }
        word = i + 1;
        while(word <= start)
        {
            write(1, &str[word], 1);
            word++;
        }
        if(i > 0 && str[i] != '\0')
        {
            write(1, " ", 1);
        }
    }
}
int main (int ac, char **av)
{
    if(ac == 2)
    {
        rev(av[1]);
    }
    write(1, "\n", 1);
}