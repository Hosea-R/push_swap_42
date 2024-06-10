/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:48:39 by mrazanad          #+#    #+#             */
/*   Updated: 2024/06/10 10:54:38 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_pile
{
	int					value;
	struct s_pile		*prev;
	struct s_pile		*next;
}						t_pile;

typedef struct s_mediane_quartile
{
	int					mediane;
	int					quartile1;
	int					quartile2;
	int					length;
}						t_mediane_quartile;

typedef struct s_input_data
{
	t_mediane_quartile	**mediane_quartile;
}						t_input_data;

// sort_three
void					sort_three(t_pile **pile_a);

// swap
void					sa(t_pile **stack_a);
void					sb(t_pile **stack_b);
void					ss(t_pile **a, t_pile **b);

// push
void					pa(t_pile **stack_a, t_pile **stack_b,
							t_mediane_quartile **mediane_quartile);
void					pb(t_pile **stack_a, t_pile **stack_b,
							t_mediane_quartile **mediane_quartile);

// rotate
void					ra(t_pile **stack_a, int print);
void					rb(t_pile **stack_b, int print);
void					rr(t_pile **stack_a, t_pile **stack_b);

// reverse rotate
void					rra(t_pile **stack_a, int print);
void					rrb(t_pile **stack_b, int print);
void					rrr(t_pile **stack_a, t_pile **stack_b);

// sort_three
void					sort_three(t_pile **stack_a);

// get instructions
int						get_index(t_pile *stack, int elem);
int						get_min(t_pile *stack);
int						get_max(t_pile *stack);
int						get_correct_position(t_pile *stack, int elem);

// utils
t_pile					*new_node(int nbr, t_pile **element);
int						add_to_stack(t_pile **stack, int nbr);
int						lentgh_stack(t_pile *stack);
void					free_stack(t_pile **stack);
void					free_mq(t_mediane_quartile **mediane_quartile);
void					free_all(t_pile **stack_a, t_pile **stack_b,
							t_mediane_quartile **mediane_quartile);

// mediane && quartile
void					put_mq(t_mediane_quartile **mediane_quartile,
							int length, int array[]);

// utils_algo
int						get_best_move(t_pile *stack_a, t_pile *stack_b);
int						already_sorted(t_pile *stack);
int						inter_quartile(t_pile *stack, int quartile1,
							int quartile2);
void					retrie_stack(t_pile **stack);

// atoi && Co
int						ft_atoi(const char *nptr);
int						ft_atoi_and_check(const char *nptr, int *error);
char					**ft_split(char const *s, char c);
char					*ft_strdup(const char *s);
size_t					ft_strlen(const char *s);

// push_swap
int						*convert_to_int_array(char **input, int length);
int						configure_mq(t_mediane_quartile *mediane_quartile,
							char **input, int length);
void					free_input(char **input, int length);
void					free_resources(t_mediane_quartile *mediane_quartile);
char					**initialize_and_process_input(int argc, char **argv,
							t_mediane_quartile *mediane_quartile);
t_mediane_quartile		*setup_mediane_quartile(int argc, char **argv);
int						initialize_and_launch_stacks(int argc, char **argv,
							t_mediane_quartile *mediane_quartile);
char					**treat_input(int argc, char **argv);
void					launch(t_pile *stack_a, t_pile *stack_b,
							t_mediane_quartile *mediane_quartile);
int						initialize_stack(t_pile **stack_a, t_pile **stack_b,
							char **in_stack);

// quick_sort
void					swap(int *a, int *b);
void					quick_sort(int array[], int small, int big);
void					get_mediane_quartile(char **input,
							t_mediane_quartile **mediane_quartile, int *error);

// optimization
void					insertion_sort(t_pile **p_a, t_pile **p_b, int b_move,
							t_mediane_quartile **mediane_quartile);
void					optimize_push_a(t_pile *stack_a, t_pile *stack_b,
							t_mediane_quartile *mediane_quartile);
void					optimize_push_b(t_pile *stack_a, t_pile *stack_b,
							t_mediane_quartile *mediane_quartile);

// validate input
int						is_valid_number(const char *str);
int						contains_duplicates(char **arr, int len);

// errors
int						copy_and_validate_args(int argc, char **argv,
							char **split);
char					**split_input(int argc, char **argv);
void					free_split(char **split);
char					**create_result(char **split);
char					**validate_and_split_input(int argc, char **argv);
int						count_strings(char **split);
int						validate_arguments(char **split);
int						is_int(const char *str);

// errors_utils
int						ft_strcmp(const char *s1, const char *s2);

#endif
