#include <stdlib.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
    int *arr;
    
    if(start > end)
    {
        arr = (int*)malloc(sizeof(int) * ((start - end) + 1));
    }
    else
    {
        arr = (int*)malloc(sizeof(int) * ((end - start) + 1));
    }
    int i = 0;
    if(!arr)
        return(NULL);
    while(start != end)
    {
        arr[i++] = end;
        if (start > end) 
        {
            end += 1;
        } 
        else 
        {
            end -= 1;
        }
    }
    arr[i] = end;
    return(arr);
}

int main (void)
{
    int start = 0;
    int end = -3;
    int i = 0;
    int *result = ft_rrange(start, end);
    while(i < 5)
    {
        printf("%d\n", result[i]);
        i++;
    }
}

//////////////////////////////////////////

#include <stdlib.h>

int ft_abs(int n)
{
    return (n < 0) ? -n : n;
}

int *ft_rrange(int start, int end)
{
    int size = ft_abs(end - start) + 1;
    int *arr = (int*)malloc(sizeof(int) * size);

    if (!arr)
        return NULL;

    int step = (start > end) ? 1 : -1;
    for (int i = 0; i < size; i++, end += step)
        arr[i] = end;
    
    return arr;
}