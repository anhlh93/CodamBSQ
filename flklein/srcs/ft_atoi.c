#include "bsq.h"

int		ft_atoi(char *str)
{
	int		nb;
	int		sign;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign *= (*str == '-' ? -1 : 1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += *str - '0';
		str++;
	}
	return (sign * nb);
}
