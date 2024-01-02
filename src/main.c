/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunan <seunan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:09:11 by seunan            #+#    #+#             */
/*   Updated: 2024/01/02 21:10:51 by seunan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_push_swap	ps;

	if (ac < 2)
		exit(EXIT_FAILURE);
	init_ps(&ps);
	parse_arg(&ps, ac, av);
	set_idx(&ps);
	if (is_sorted(&ps))
		exit(EXIT_SUCCESS);
	sort(&ps);
	free_q(&ps);
	return (0);
}
