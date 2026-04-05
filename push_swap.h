/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:05:06 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/17 18:41:40 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;
typedef struct s_pivots
{
	int	last_pivot;
	int	pivot1;
	int	pivot2;
	int	size_max;
}	t_pivots;

void			free_stack(t_list **stack);
int				ft_is_ascending(t_list **stack);
int				stack_size(t_list *stack);
void			indexing(t_list **stacka);
void			optimize_final_sort(t_list **stack_a, t_list **stack_b);
void			ft_push_swap(t_list **a, t_list **b);
void			sort_3(t_list **stack);
void			sort_4(t_list **a, t_list **b);
void			sort_5(t_list **a, t_list **b);
void			reverse_rotate(t_list **stack, char *op);
void			rotate(t_list **stack, char *op);
void			push_b(t_list **a, t_list **b);
void			push_a(t_list **b, t_list **a);
void			swap(t_list **stack, char *op);
void			ft_rrr(t_list **stacka, t_list **stackb, char *op);
long long int	ft_l_atoi(const char *str);
int				ft_lstsize(t_list *lst);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			check_input(int ac, char **av);
t_list			*ft_change_input(int ac, char **av);
void			error_exit(void);
int				ft_printf(const char *format, ...);
void			ft_putchar(char c, int *count);
void			ft_putstr(char *s, int *count);
void			ft_putnbr(long n, int *count);
void			ft_putunsigned(unsigned int n, int *count);
void			ft_puthex(unsigned long n, int uppercase, int *count);
void			ft_putptr(unsigned long ptr, int *count);
char			*get_next_line(int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
void			ft_min_fill(t_list **stack_a, t_list **stack_b,
					int last_pivot, int pivot2);
int				ft_atoi(const char *str);
int				get_position(t_list **stack_b, int target_index);
void			initialize_pivots(t_pivots *pivots, t_list **stack_a);
void			process_stack_a(t_list **stack_a, t_list **stack_b,
					t_pivots *pivots);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			**ft_split(char const *s, char c);
char			**handling_arg(int ac, char **av);
void			ft_free(char **strs, size_t j);

#endif