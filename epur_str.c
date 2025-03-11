#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int deli(char *str)
{
    return(*str == ' ' || (*str >= 9 && *str <= 13)? 1 : 0);
}

void epur(char *str)
{
    int i = 0;
    int first_word = 1;

    while (str[i])
    {
        while (str[i] && deli(&str[i])) // Skip leading spaces
            i++;
        if (!str[i])
            break;
        if (!first_word)
            write(1, " ", 1);
        first_word = 0;
        while (str[i] && !deli(&str[i])) // Print the word
            write(1, &str[i++], 1);
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        epur(av[1]);
    }
    else
    {
        write(1, "\n", 1);
    }
    return(0);
}