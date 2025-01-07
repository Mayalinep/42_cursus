/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmore_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpelage <mpelage@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:30:31 by mpelage           #+#    #+#             */
/*   Updated: 2025/01/07 19:14:56 by mpelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_max(t_stack **pile)
{
	t_stack	*temp;
	t_stack	*max_node;
	int		max;

	max = INT_MIN;
	temp = *pile;
	max_node = NULL;
	while (temp)
	{
		if (temp->data > max)
		{
			max = temp->data;
			max_node = temp;
		}
		temp = temp->next;
	}
	return (max_node);
}

int	find_half(t_stack **pile, int max, int size)
{
	t_stack	*current;

	current = *pile;
	while (size > 0 && current)
	{
		if (current->data == max)
			return (1);
		current = current->next;
		size--;
	}
	return (0);
}
