#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers using
 *             the Jump search algorithm
 *
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located
 *         NULL if value is not present in list or if head is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    listint_t *curr = list, *prev = NULL;
    size_t jump = sqrt(size), i, low = 0, high = jump;

    if (!list)
        return (NULL);

    while (high < size && curr->index < high)
    {
        prev = curr;
        curr = curr->next;
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
        if (curr->n >= value)
        {
            printf("Value found between indexes [%lu] and [%lu]\n", prev->index, curr->index);
            while (prev->index <= curr->index)
            {
                printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
                if (prev->n == value)
                    return (prev);
                prev = prev->next;
            }
            return (NULL);
        }
        low = high;
        high += jump;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", low, high);
    while (prev->index < high && prev->index < size)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (prev->n == value)
            return (prev);
        prev = prev->next;
    }

    printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
    return (NULL);
}
