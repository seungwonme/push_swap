/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:40:51 by seunan            #+#    #+#             */
/*   Updated: 2024/01/02 21:11:18 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	split_enque(t_push_swap *ps, int ac, char *av[])
{
	while (av[ac] != NULL)
	{
		enque(&ps->a, FRONT, new_node(ft_atoi(av[ac])));
		++ac;
		++ps->sum;
	}
	if (ps->sum == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	ac = 0;
	while (av[ac] != NULL)
	{
		free(av[ac]);
		++ac;
	}
	free(av);
}

void	parse_arg(t_push_swap *ps, int ac, char *av[])
{
	int	i;

	if (ac == 2)
	{
		ac = 0;
		av = ft_split(av[1], ' ');
		split_enque(ps, ac, av);
	}
	i = 1;
	while (i < ac)
	{
		enque(&ps->a, FRONT, new_node(ft_atoi(av[i])));
		++i;
		++ps->sum;
	}
}

t_deque_node	*new_node(int value)
{
	t_deque_node	*node;

	node = (t_deque_node *)calloc(1, sizeof(t_deque_node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_q(t_push_swap *ps)
{
	t_deque_node	*temp;

	temp = ps->a.node[FRONT];
	while (temp)
	{
		ps->a.node[FRONT] = ps->a.node[FRONT]->next;
		free(temp);
		temp = ps->a.node[FRONT];
	}
	temp = ps->b.node[FRONT];
	while (temp)
	{
		ps->b.node[FRONT] = ps->b.node[FRONT]->next;
		free(temp);
		temp = ps->b.node[FRONT];
	}
}
