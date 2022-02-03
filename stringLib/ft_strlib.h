#ifndef FT_STRLIB_H
# define FT_STRLIB_H

# include <unistd.h>

int		ft_strcmp(char *left, char *right);

void	ft_puts(char *str);

char	*ft_strcpy(char *dest, char *src);

int		ft_strlen(char *str);

void	ft_strrev(char *str);

int		ft_isspace(char c);

int		ft_is_printable(char c);

int		ft_is_numeric(char c);

int		ft_str_is_numeric(char *str);

#endif
