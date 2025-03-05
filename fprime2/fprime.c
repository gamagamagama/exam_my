#include <stdlib.h>
#include <stdio.h>

int is_prime(int num)
{
    int i = 2;
    if(num <= 1)
        return(0);
    while(i * i < num)
    {
        if(num % i == 0)
            return(0);
        i++;
    }
    return(1);
}

void fprime(int num)
{
    int factor = 2;
    int flag = 1;
   
	if (num == 1)
		printf("1");

	while (factor <= num)
	{
		if (num % factor == 0 && is_prime(factor))
		{
			if (flag == 1)
				printf("%d", factor);
			else
				printf("*%d", factor);
			flag = 0;
			num = num / factor;
		}
		else
			++factor;
	}
}


int main (int ac, char **av)
{

    int num;
    if(ac == 2)
    {
       num = atoi(av[1]);
        fprime(num);
    }
    printf("\n");
	return (0);
}