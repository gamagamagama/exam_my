#include<string.h>
size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t count = 0;
    char arr_rejected[256] = {0};
    int i =0;
    while (reject[i])
    {
        arr_rejected[(unsigned char)reject[i]] = 1;
        i++;
    }
    while(s[count])
    {
        if(arr_rejected[(unsigned char)s[count]])
            break;
        count++;
    }
    return(count);
}