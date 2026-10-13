/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadandi <sbadandi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 16:01:18 by sbadandi          #+#    #+#             */
/*   Updated: 2026/10/13 20:40:36 by sbadandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	t_list	*node1;
	t_list 	*node2;
	t_list  *node3;
	t_list  *node4;
	t_list  *node5;
	t_list  *head;


	node1 = (ft_lstnew("sgoor"));
	node2 = (ft_lstnew("badandi"));
	node3 = (ft_lstnew("ali"));
	node4 = (ft_lstnew("ahmad"));
	node5 = (ft_lstnew("saif"));
	
	head = node2;
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node4);
	ft_lstadd_front(&head, node5);
	ft_lstadd_back(&head, node1);
	
	int	i = 5;
	t_list *tmp;
	tmp = head;
	while(tmp->next)
	{
		printf("node%d[%s]\n",i,(char *)tmp->content);
		tmp = tmp->next;
		i--;
	}

	int	len = (int)ft_lstsize(head);
	printf("lst_len = %d\n", len);
}
