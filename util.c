#include "main.h"

int ft_strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

int ft_atoi(const char *str)
{
	long long result;
	int sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (int)(result * sign);
}