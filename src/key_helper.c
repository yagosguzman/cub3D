/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:18:34 by gpinilla          #+#    #+#             */
/*   Updated: 2024/07/14 12:09:47 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_key_node	*create_key_node(int keycode)
{
	t_key_node	*node;

	node = (t_key_node *)safe_malloc(sizeof(t_key_node));
	if (node)
	{
		node->keycode = keycode;
		node->is_pressed = 0;
		node->next = NULL;
	}
	return (node);
}

t_key_node	*find_key_node(t_key_node *head, int keycode)
{
	t_key_node	*current;

	current = head;
	while (current)
	{
		if (current->keycode == keycode)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	add_key_node(t_key_node **head, int keycode)
{
	t_key_node	*new_node;

	new_node = create_key_node(keycode);
	if (new_node)
	{
		new_node->next = *head;
		*head = new_node;
	}
}

void	set_key_state(t_key_node **head, int keycode, int is_pressed)
{
	t_key_node	*node;

	node = find_key_node(*head, keycode);
	if (!node)
	{
		add_key_node(head, keycode);
		node = *head;
	}
	node->is_pressed = is_pressed;
}

int	get_key_state(t_key_node *head, int keycode)
{
	t_key_node	*node;

	node = find_key_node(head, keycode);
	if (node)
		return (node->is_pressed);
	return (0);
}
