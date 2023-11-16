#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed
 */
void free_list(list_t *head)
{
    list_t *tmp;

    while (head)
    {
        tmp = head->next;
        /* Check if the string is not NULL before freeing */
        if (head->str)
            free(head->str);
        free(head);
        head = tmp;
    }
}
