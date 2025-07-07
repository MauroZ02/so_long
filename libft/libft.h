/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:06:54 by mzangaro          #+#    #+#             */
/*   Updated: 2025/07/07 17:42:19 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFFER_SIZE 42

# define HEX_LOW_BASE "0123456789abcdef"
# define HEX_UPP_BASE "0123456789ABCDEF"

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

char	*get_next_line(int fd);
char	*next_line(char *buffer);
char	*extract_line(char *buffer);
char	*read_till_nl(int fd, char *rest);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
void	*ft_calloc_gnl(size_t n, size_t size);
size_t	ft_strlen_gnl(const char *s);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size);
size_t	ft_strlcpy_gnl(char *dest, char *src, size_t size);
char	*ft_strchr_gnl(const char *s, int c);

int		print_char(int c);
int		print_str(char *str);
int		print_format(char specifier, va_list args);
int		ft_printf(const char *format, ...);
int		print_dec(int n);
int		print_hex(unsigned int n, const char *symbols);
int		print_long(unsigned long n, const char *symbols);
int		print_unsigned(unsigned int n);
int		print_ptr(void *n, const char *symbols);

#endif