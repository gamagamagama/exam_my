#include <stdio.h>

static int	is_valid_char(char c, int base)
{
	if (c >= '0' && c <= '9')
		return (c - '0' < base);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10 < base);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10 < base);
	return (0);
}

static int	char_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;

	if (!str || str_base < 2 || str_base > 16)
		return (0);

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}

	while (*str && is_valid_char(*str, str_base))
	{
		result = result * str_base + char_to_int(*str);
		str++;
	}

	return (result * sign);
}
