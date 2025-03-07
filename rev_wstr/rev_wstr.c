#include <unistd.h>

void write_str(char *str, int len)
{
    write(1, str, len);
}

void rev_wstr(char *str, char separ)
{
    int i = 0, end, start;
    while (str[i])
        i++;
    end = i - 1;
    while (end >= 0)
    {
        while (end >= 0 && str[end] == separ)
            end--;
        if (end < 0)
            break;
        start = end;
        while (start >= 0 && str[start] != separ)
            start--;
        write_str(&str[start + 1], end - start);
        if (start >= 0)
            write(1, " ", 1);
        end = start - 1;
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
        rev_wstr(av[1], ' ');
    return 0;
}
