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

void		ft_echo(char **str)
{
	char	**s;

	while (*++str != '\0')
	{
		s = ft_strsplit(*str, '"');
		ft_putstr(*s);
		ft_putchar(' ');
		free(s);
	}
	ft_putchar('\n');
}
