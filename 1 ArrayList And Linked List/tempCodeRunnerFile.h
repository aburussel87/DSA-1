else if (list->tail == NULL)
    {
        list->head->next = n;
        n->prev = list->head;
        list->tail = n;
    }