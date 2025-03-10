#include<stdio.h>
#include<stdlib.h>
int deli(char c)
{
    return((c == ' ' || (c >= 9 && c <= 13)) ? 1 : 0);
}

int num_words(char *str)
{
    int wo_c = 0;
   while(*str)
   {
        while(deli(*str))
            str++;
        if((*str))
        {
            wo_c++;
            while(*str && !deli(*str))
            {
                str++;
            }
        }
   }
    return(wo_c);

}
int wo_len(char *str)
{
    int i = 0;
  
    while(str[i] && !deli(str[i]))
    {
        i++;
    }
    return(i);
    

}
char *cp_word(const char *str, int wlen)
{
    int i = 0;
    if(!str || wlen <= 0)
        return(NULL);
    char *new_word = (char *)malloc((wlen + 1) * sizeof(char));
    if(!new_word)
        return(NULL);
    while(str[i] && (i < wlen))
    {
        new_word[i] = str[i];
        i++;
    }
    new_word[i] = '\0';
    return(new_word);
}

char **ft_split(char *str)
{
    int num_wo = num_words(str);

    char **array = (char**)malloc((num_wo + 1) * (sizeof(char *)));
    if(!array)
        return(NULL);
    int i = 0;
    while(*str)
    {
        while(deli(*str))
            str++;
        const char *start = str;
        if(*str)
        {
           while(*str && !deli(*str))
           {
                str++;
           }
        }
        array[i++] = cp_word(start, str - start);
    }
    array[i] = NULL;
    return(array);

    
}

void print_array(char **arr)
{
    if (!arr) return;
    for (int i = 0; arr[i]; i++)
    {
        printf("Word %d: %s\n", i, arr[i]);
        free(arr[i]);
    }
    free(arr);
}

int main()
{
    char str[] = "   Hello \t world \n this is \t C  ";
    char **words = ft_split(str);
    print_array(words);
    return 0;
}