#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int is_prime(int prime)
{
    for(int del = 2; del * del <= prime; del++)
    {
        if(prime % del == 0)
            return(0);
    }
    return(1);
}
int ato(char *str)
{
    int num = 0;
    while (*str && (*str >= '0' && *str<= '9'))
    {
        num = num * 10 + (*str - '0');
        str++;
    }
    return(num);
}
void ptnm(int num)
{
    char dig;
  if (num > 9)
  {
    ptnm(num / 10);
  }
  dig = num % 10 + '0';
  write(1, &dig, 1);
    
}
void aps(char *str)
{
  int num = ato(str);
  int aps = 0;
  int deli = 2;
  while(num >= deli)
  {
    if(is_prime(deli))
    {
        aps = aps + deli;
    }
    deli++;
  }
  ptnm(aps);
}
int main (int ac, char **av)
{
    if(ac == 2)
    {
        aps(av[1]);
    }
    write(1, "\n", 1);
}