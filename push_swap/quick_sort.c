// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   quick_sort.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: asafrono <asafrono@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/27 18:17:09 by asafrono          #+#    #+#             */
// /*   Updated: 2024/12/03 15:22:57 by asafrono         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// int get_nth_value(t_node *stack, int n)
// {
//     t_node *current;
//     int i;

//     if (!stack)
//         return (0);

//     current = stack;
//     i = 0;
//     while (current && i < n)
//     {
//         current = current->next;
//         i++;
//     }

//     if (current)
//         return (current->value);
//     return (0);
// }
// void quick_sort_a(t_node **stack_a, t_node **stack_b, int size)
// {
//     int pivot;
//     int elements_less;

//     // Base cases
//     if (size <= 1)
//         return;
//     if (size <= 3)
//     {
//         sort_small_a(stack_a, size);
//         return;
//     }
//     if (is_sorted(*stack_a, size))
//         return;

//     // Find pivot and partition
//     pivot = find_pivot(*stack_a, size);
//     elements_less = partition_a(stack_a, stack_b, size, pivot);

//     // Sort both partitions
//     quick_sort_b(stack_a, stack_b, elements_less);        // Sort elements in B
//     quick_sort_a(stack_a, stack_b, size - elements_less); // Sort remaining elements in A
    
//     // Merge the sorted partitions
//     merge_from_b(stack_a, stack_b, elements_less);
// }

// void quick_sort_b(t_node **stack_a, t_node **stack_b, int size)
// {
//     if (size <= 1)
//     {
//         if (size == 1)
//             pa(stack_a, stack_b);
//         return;
//     }
//     if (size <= 3)
//     {
//         sort_small_b(stack_a, stack_b, size);
//         return;
//     }

//     int pivot = find_pivot(*stack_b, size);
//     int elements_greater = partition_b(stack_a, stack_b, size, pivot);

//     quick_sort_a(stack_a, stack_b, elements_greater);
//     quick_sort_b(stack_a, stack_b, size - elements_greater);
// }

// int partition_a(t_node **stack_a, t_node **stack_b, int size, int pivot)
// {
//     int elements_less = 0;
//     int rotations = 0;
//     int i;

//     for (i = 0; i < size; i++)
//     {
//         if ((*stack_a)->value <= pivot)
//         {
//             pb(stack_a, stack_b);
//             elements_less++;
//         }
//         else
//         {
//             ra(stack_a);
//             rotations++;
//         }
//     }

//     // Restore the stack order
//     i = 0;
//     while (i < (size - elements_less))
//     {
//         rra(stack_a);
//         i++;
//     }

//     return elements_less;
// }
// int partition_b(t_node **stack_a, t_node **stack_b, int size, int pivot)
// {
//     int elements_greater = 0;
//     int rotations = 0;
//     int i;

//     printf("Before partitioning B: ");
//     print_stack(*stack_b);
//     printf("Pivot: %d\n", pivot);

//     for (i = 0; i < size; i++)
//     {
//         if ((*stack_b)->value >= pivot)
//         {
//             pa(stack_a, stack_b);
//             elements_greater++;
//         }
//         else
//         {
//             rb(stack_b);
//             rotations++;
//         }
//     }

//     // Restore the stack order
//     while (rotations > 0)
//     {
//         rrb(stack_b);
//         rotations--;
//     }

//     printf("After partitioning B: ");
//     print_stack(*stack_b);
//     printf("Stack A after partitioning B: ");
//     print_stack(*stack_a);

//     return elements_greater;
// }

// // New function to merge elements from B back to A
// void merge_from_b(t_node **stack_a, t_node **stack_b, int size)
// {
//     while (size--)
//     {
//         pa(stack_a, stack_b);
//         if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
//             sa(stack_a);
//     }
// }

// // Helper function to find a better pivot
// int find_pivot(t_node *stack, int size)
// {
//     if (size <= 1)
//         return stack->value;
    
//     // Get first, middle, and last values
//     int first = stack->value;
//     int middle = get_nth_value(stack, size / 2);
//     int last = get_nth_value(stack, size - 1);
    
//     // Return the median of three
//     if ((first <= middle && middle <= last) || (last <= middle && middle <= first))
//         return middle;
//     if ((middle <= first && first <= last) || (last <= first && first <= middle))
//         return first;
//     return last;
// }

// // Improved sort_small_a function
