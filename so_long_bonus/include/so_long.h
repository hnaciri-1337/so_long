/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:01:28 by hnaciri-          #+#    #+#             */
/*   Updated: 2022/03/07 18:17:40 by hnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define X 64

typedef struct s_enemies
{
	int					number;
	int					i;
	int					j;
	struct s_enemies	*next;
}				t_enemies;

typedef struct s_data
{
	char		**the_map;
	int			coin;
	int			i;
	int			j;
	int			anime;
	int			move;
	void		*mlx;
	void		*mlx_win;
	int			*array;
	t_enemies	*enemies;
}				t_data;

void		*ft_door(void *mlx);
void		*ft_wall(void *mlx);
void		*ft_messi(void *mlx);
void		*ft_messi2(void *mlx);
void		*ft_coin(void *mlx);
void		*ft_player(void *mlx);
void		*ft_sand(void *mlx);
void		ft_enemies(t_data *data);
int			ft_enemie_up(t_data *data, t_enemies *enemies);
int			ft_enemie_down(t_data *data, t_enemies *enemies);
int			ft_enemie_right(t_data *data, t_enemies *enemies);
int			ft_enemie_left(t_data *data, t_enemies *enemies);
int			enemies(t_data *data);
int			ft_open(char *map, int *i);
int			ft_check_first(char *line);
void		ft_check(int fd, char *map, t_data *data);
void		ft_check_last(char *line, int len);
void		ft_check_line(char *line, t_data *s);
void		ft_start(char	*map, int fd, t_data *data);
void		ft_count_coins(t_data *data);
void		ft_count_player(char **the_map, int i);
int			ft_move_down(t_data *data);
int			ft_move_up(t_data *data);
int			ft_move_left(t_data *data);
int			ft_move_right(t_data *data);
int			ft_swap_left(t_data *data, int i, int j);
int			ft_swap_up(t_data *data, int i, int j);
int			ft_swap_right(t_data *data, int i, int j);
int			ft_swap_down(t_data *data, int i, int j);
int			ft_swape_up(t_data *data, int i, int j);
int			ft_swape_down(t_data *data, int i, int j);
int			ft_swape_right(t_data *data, int i, int j);
int			ft_swape_left(t_data *data, int i, int j);
void		ft_win(t_data *s);
int			ft_printf(const char *s, ...);
void		ft_count_exit(char **the_map, int l);
void		coins_num(char **the_map, int l);
void		ft_lose(t_data *s);
int			ft_lose_red(t_data *s);
void		ft_draw_help(char c, int x, int y, t_data *data);
void		ft_count_enemies(t_data *data);
void		ft_lstadd_back(t_enemies **lst, t_enemies *new);
t_enemies	*ft_lstlast(t_enemies *lst);
t_enemies	*ft_lstnew(int i, int j, int number);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_itoa(int n);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char*s2, size_t n);
char		*ft_strdup(char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
char		*get_next_line(int fd);
int			ft_putnbr(long int n);
int			ft_counter(long unsigned int nbr);
int			ft_putchar(char c);
int			ft_putstr(char	*str);
int			ft_check_and_print(va_list args, char c);
int			ft_putlowerbase(long unsigned int nbr);
int			ft_putupperbase(unsigned int nbr);
int			ft_putaddress(long unsigned int address);
#endif
