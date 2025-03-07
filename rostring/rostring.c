#include <unistd.h>
void write_str(char *str, int len)
{
    write(1, str, len);
}

void rostring(char *str)
{
    int start_word = 0;
    int end_word = 0;
    int start = 0;
    int end = 0;
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t')
    {
        i++;
    }
    start_word = i;
    while(str[i] && str[i] != ' ' && str[i] != '\t')
    {
        i++;
    }
    end_word = i;
    while (str[i])
    {
        while(str[i] == ' ' || str[i] == '\t')
        {
            i++;
        }
        if(!str[i])
        {
            break;
        }
        start = i;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
        {
            i++;
        }
        end = i;
        write_str(&str[start], end - start);
        write(1, " ", 1);
    }
    if(end_word > start_word)
    {
        write_str(&str[start_word], end_word - start_word);
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if(ac > 1)
        rostring(av[1]);
    write(1, "\n", 1);
}