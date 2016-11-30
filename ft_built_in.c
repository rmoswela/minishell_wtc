#include "minishell.h"

void		ft_change_dir(char **str)
{
	char	*cmd_home;

	if (*++str == NULL)
		chdir(*str);
	else
	{
		cmd_home = my_getenv("HOME");
		chdir(cmd_home);
	}
}

void		ft_environVariable(char **my_env, char *environVar)
{
	int	iLen;
	int	loop;

	iLen = ft_strlen(environVar);
	loop = 0;
	while (my_env[loop] != '\0')
	{
		if (ft_strncmp(my_env[loop], environVar, iLen) == 0)
		{
			ft_putstr(my_env[loop]);
			return ;
		}
		loop++;
	}
}

void		ft_echo(char **str)
{
	char	**s;
	int	iLen;
	char	*subString;

	iLen = ft_strlen(str[1]);
	if (str[1][0] == 36)
	{
		subString = ft_strsub(str[1], 1, iLen);
		s = ft_env();
		ft_environVariable(s, subString);
	}
	else
	{
		while (*++str != '\0')
		{
			s = ft_strsplit(*str, '"');
			ft_putstr(*s);
			ft_putchar(' ');
			free(s);
		}
	}
	ft_putchar('\n');
}
