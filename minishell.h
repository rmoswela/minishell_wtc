/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 18:26:46 by rmoswela          #+#    #+#             */
/*   Updated: 2016/11/29 21:17:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MINISHELL_BUFFSIZE 1024
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

int	ft_strlen(const char *str);
int	ft_check_char (char *str, char c);
int	ft_strcmp(char *s1, char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_shell_read_line(void);
char	**ft_strsplit(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *str1, const char *str2);
char	*ft_strdup (char *str);
char	**ft_env();
char	*ft_check_path();
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strcpy(char *dest, char *src);
char	**ft_split_line(char *line, char c);
char	*ft_strtrim(char *str);
char	*my_getenv(char *str);
char	*ft_strstr (char *str, char *sub);
char	*ft_check_command(char *str);
char	ft_get_char();
void	ft_putendl (char const *str);
void	ft_bzero (char *s, size_t n);
void	ft_perror (char *str);
void	ft_change_dir (char **str);
void	ft_echo (char **str);
void	ft_putchar(char c);
void	ft_setenv (char *name, char *value, char *overwrite);
void	ft_val_setenv (char *name);
void	ft_unsetenv (char *name);
void	ft_putstr(char *str);
void	ft_output_redirection (char *str);
void	ft_double_output_redirect (char *str);
void	ft_input_redirection (char *str);
void	ft_double_input_redict (char *str);
void	ft_execute(char *str, char **args);

# endif
