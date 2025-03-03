#include <stdio.h>
#include <unistd.h>
int word_len(char *str, int i)
{
    while(str[i] != ' ' && str[i] != '\t' && str[i])
    {
        i++;
    }
    return(i - 1);
}

int is_char(char *str, int i)
{
    return((str[i] >= 'A' &&str[i] <= 'Z') || (str[i] >= 'a' &&str[i] <= 'z'));
}

char *decapitalize( char *str)
{
   int i = 0;
    while(str[i])
    {
        if (str[i] >= 'A' && str[i]<= 'Z')
        {
            str[i] += 32;
        }
        i++;
    }
    return(str);
}

int main (int ac, char **av)
{
   
    int num_str = 1;
    int i = 0;

    if(ac < 2)
    {
        write(1, "\n", 1);
    }
    else
    {
        while (num_str < ac)
        {
            char *str = av[num_str];
            str = decapitalize(str);
            i=0;
            while(str[i])
            {
                if(is_char(str, i))
                {
                    int last_char = word_len(str, i);
                    if((str[last_char] >= 'a' && str[last_char] <= 'z'))
                    {
                        str[last_char] -= 32;
                    }                    
                }
                write(1, &str[i], 1);
                i++;
            }
            write(1, "\n", 1);
            num_str++;
        }

    }
   

}