#include "minishell.h"

char	*ft_strdup (char *str)
{
	int iLen;
	iLen = ft_strlen(str);
	char *duplicate;
	duplicate = (char *)malloc(ft_strlen(str) + 1);
	duplicate[iLen] = '\0';
	if (duplicate == NULL)
		EXIT_FAILURE;
	else
		ft_strcpy(duplicate, str);
	return (duplicate);
}
