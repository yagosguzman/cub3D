/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:24:07 by gpinilla          #+#    #+#             */
/*   Updated: 2024/06/23 13:10:16 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*BUFFER DEFINITION*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

/*
** Struct
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
**  Libft functions
*/

void				*ft_memset(void *dest, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t blen);
char				*ft_strdup(const char *s);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
/*
**  Get_next_line
*/
char				*get_next_line(int fd);
/*Functions of get_next_line_utils*/
char				*ft_strjoin_line(char *s1, char *s2);
size_t				ft_strlen_line(char *s);
char				*ft_strchr_line(char *s, int c);
char				*ft_substr_line(char *s, unsigned int start, size_t len);
char				*ft_strdup_line(char *s);
void				*ft_free(void *s);

/*
**  Printf functions
*/
int					ft_printf(char const *format, ...);

/*Characters functions*/

void				print_character(int c, int *leng);
void				print_string(char *s, int *leng);
void				print_up_hexadecimal_memory(intptr_t memory_number,
						int *leng);
void				print_direc_memory(void *ptr, int *leng);
/*Numbers functions*/
void				print_integer(int number, int *leng);
void				print_integer_in_base(int number, int *leng);
void				print_unsigned_integer(unsigned int number, int *leng);
void				print_low_hexadecimal(int number, int *leng);
void				print_up_hexadecimal(int number, int *leng);

#endif
