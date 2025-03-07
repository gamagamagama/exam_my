#include <stdlib.h>

static int word_count(const char *s, char c)
{
    int count = 0;

    while (*s)
    {
        while (*s == c) // Skip delimiters
            s++;
        if (*s) // If it's a word
        {
            count++;
            while (*s && *s != c) // Move to the end of the word
                s++;
        }
    }
    return count;
}

static char *word_dup(const char *start, int len)
{
    char *word = (char *)malloc((len + 1) * sizeof(char));
    if (!word)
        return NULL;
    
    for (int i = 0; i < len; i++)
        word[i] = start[i];

    word[len] = '\0';
    return word;
}

char **ft_split(char const *s, char c)
{
    if (!s)
        return NULL;
    
    int words = word_count(s, c);
    char **result = (char **)malloc((words + 1) * sizeof(char *));
    if (!result)
        return NULL;

    int i = 0;
    while (*s)
    {
        while (*s == c) // Skip delimiters
            s++;

        if (*s) // Start of a word
        {
            const char *word_start = s;
            while (*s && *s != c) // Move to the end of the word
                s++;

            result[i++] = word_dup(word_start, s - word_start);
        }
    }
    
    result[i] = NULL;
    return result;
}