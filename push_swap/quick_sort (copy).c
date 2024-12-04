/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort (copy).c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:17:09 by asafrono          #+#    #+#             */
/*   Updated: 2024/12/03 15:01:05 by asafrono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_nth_value(t_node *stack, int n)
{
    t_node *current;
    int i;

    if (!stack)
        return (0);

    current = stack;
    i = 0;
    while (current && i < n)
    {
        current = current->next;
        i++;
    }

    if (current)
        return (current->value);
    return (0);
}

void quick_sorting(t_node **stack_a, t_node **stack_b, int l, int r)
{
    int q;
	printf("Quick sorting: l=%d, r=%d\n", l, r);
    print_stack(*stack_a);

    if (is_sorted(*stack_a, r - l))
        return;
    else if ( (r-l) <= 3)
    {
        sort_small(stack_a, r - l);
        return;
    }

    if (r > l)
    {
        q = partition(stack_a, stack_b, l, r);
        quick_sorting(stack_a, stack_b, l, q - 1);
        quick_sorting(stack_a, stack_b, q + 1, r);
    }
}

int partition(t_node **stack_a, t_node **stack_b, int l, int r)
{
    int pivot;
    int i;
    int j;

    pivot = get_nth_value(*stack_a, (l + r) / 2);
    i = l;
    j = r;
	printf("Partition: l=%d, r=%d, pivot=%d\n", l, r, pivot);
    while (i <= j)
    {
        while (i <= r && get_nth_value(*stack_a, i) < pivot)
            i++;
        while (j >= l && get_nth_value(*stack_a, j) > pivot)
            j--;
        if (i > j)
            break;
        swap_elements(stack_a, stack_b, i, j);
		printf("i=%d, j=%d\n", i, j);
        i++;
        j--;
    }
    return (j);
}
void swap_elements(t_node **stack_a, t_node **stack_b, int index1, int index2)
{
    int size = get_stack_size(*stack_a);
    int i;
    
	if (index1 < 0 || index2 < 0 || index1 >= size || index2 >= size || index1 == index2)
    {
        // Handle error (e.g., print error message, return, or exit)
        return;
    }
	// Ensure index1 is smaller than index2
    if (index1 > index2)
    {
        int temp = index1;
        index1 = index2;
        index2 = temp;
    }
    if (index1 == 0 && index2 == 1)
    {
        sa(stack_a);
        return;
    }
    
    // Move element at index1 to top of stack_a
    i = 0;
    while (i < index1)
    {
        ra(stack_a);
        i++;
    }
    
    // Push element to stack_b
    pb(stack_a, stack_b);
    
    // Move element at index2 to top of stack_a
    i = 0;
    while (i < (index2 - index1))
    {
        ra(stack_a);
        i++;
    }
    
    // Swap elements
    sa(stack_a);
    pa(stack_b, stack_a);
    
    // Rotate stack back to original position
    i = 0;
    while (i < (size - index2))
    {
        rra(stack_a);
        i++;
    }
}





void quick_sorting(t_node **stack_a, t_node **stack_b, int l, int r)
{
    int pivot;
    int elements_to_push;
    int elements_pushed;
    int mid;

    printf("Quick sorting: l=%d, r=%d\n", l, r);
    print_stack(*stack_a);

    if (r - l <= 3)
    {
        sort_small(stack_a, r - l);
        return;
    }

    mid = l + (r - l) / 2;
    pivot = get_nth_value(*stack_a, mid);
    elements_to_push = r - l + 1;
    elements_pushed = 0;

    while (elements_to_push > 0)
    {
        if ((*stack_a)->value < pivot)
        {
            pb(stack_a, stack_b);
            elements_pushed++;
        }
        else
        {
            ra(stack_a);
        }
        elements_to_push--;
    }

    // Rotate back the elements that were not pushed
    elements_to_push = r - l + 1;
    while (elements_to_push > elements_pushed)
    {
        rra(stack_a);
        elements_to_push--;
    }

    // Push back elements from B to A
    while (elements_pushed > 0)
    {
        pa(stack_b, stack_a);
        elements_pushed--;
    }

    // Recursively sort the left and right partitions
    if (l < mid)
        quick_sorting(stack_a, stack_b, l, mid - 1);
    if (mid <= r)
        quick_sorting(stack_a, stack_b, mid, r);
}
