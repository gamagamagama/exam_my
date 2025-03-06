#include <stdlib.h>

int		absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int		get_len(int nbr)
{
	int len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char *result;
	int len;

	len = get_len(nbr);
	result = malloc(sizeof(char) * (len + 1));
	result[len] = '\0';

	if (nbr < 0)
		result[0] = '-';
	else if (nbr == 0)
		result[0] = '0';

	while (nbr != 0)
	{
		--len;
		result[len] = absolute_value(nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (result);
}


///////////////////////////////////////////////////////////////
static int	numlen(int n)
{
    int len = (n <= 0); 
    while (n != 0)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char	*ft_itoa(int n)
{
	char *num_str = (char *)malloc(sizeof(char) * (len + 1));
	int	len = numlen(n);
	int	sign = 1;

	if (!num_str)
		return (NULL);
	num_str[len] = '\0';
	len--;
	if (n < 0)
	{
		num_str[0] = '-';
		sign = -1;
	}
	if (n == 0)
		num_str[len] = '0';
	while (n != 0)
	{
		num_str[len] = (char)(((n % 10) * sign) + '0');
		n /= 10;
		len--;
	}
	return (num_str);
}
