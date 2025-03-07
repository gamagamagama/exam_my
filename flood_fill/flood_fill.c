#include <stdlib.h>
#include <stdio.h>

typedef struct  s_point
{
  int           x;
  int           y;
}               t_point;

void fill(char **tab, t_point size, t_point start, char to_fill)
{
    if(start.x < 0 || start.x >= size.x || start.y < 0 || start.y >= size.y || tab[start.y][start.x] != to_fill)
    {
        return;
    }
    tab[start.y][start.x] = 'F';
    int directions[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    for(int i = 0; i < 4; i++)
    {
        t_point next = {start.x + directions[i][0], start.y + directions[i][1]};
        fill(tab, size, next, to_fill);
    }
}
void  flood_fill(char **tab, t_point size, t_point begin)
{
    fill(tab, size, begin, tab[begin.y][begin.x]);
}
