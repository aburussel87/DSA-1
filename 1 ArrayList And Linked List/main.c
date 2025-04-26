#include "arraylist.h"
// #include"linkedlist.h"
#include <stdio.h>

int main()
{
    FILE *file = fopen("in2.txt", "r");
    FILE *fout;
    fout = freopen("output.txt","w",stdout);
    if (file == NULL)
    {

        return 1;
    }

    int capacity;
    int size;
    fscanf(file, "%d %d", &size, &capacity);

    ArrayList list;
    init_arraylist(&list, capacity);
    // LinkedList list;
    // init_linkedlist(&list);
    int i;
    for (i = 0; i < size; i++)
    {
        int value;
        fscanf(file, "%d", &value);
        append(&list, value);
    }
    print_list(&list);
    printf("\n");

    int func, param;
    while (fscanf(file, "%d %d", &func, &param) == 2 && func != 0)
    {
        if (func == 1)
        {
            insert(&list, param);
            printf("Inserted %d\n", param);
        }
        else if (func == 2)
        {
            int value = remove_at_current(&list);
            if(value != __INT_MAX__)
            printf("Removed %d\n", value);
        }
        else if (func == 3)
        {
            int ret = find(&list, param);
            if (ret != -1)
                printf("Found %d at %d\n", param, ret);
            else
                printf("Couldnt found %d\n", param);
        }
        else if (func == 4)
        {
            printf("Moved current position to 0\n");
            move_to_start(&list);
        }
        else if (func == 5)
        {
            printf("Moved current postion to end\n");
            move_to_end(&list);
        }
        else if (func == 6)
        {
            prev(&list);
        }
        else if (func == 7)
        {
            next(&list);
        }
        else if (func == 8)
        {
            int pos = get_current_position(&list);
            printf("Current position is %d\n", pos);
        }
        else if (func == 9)
        {
            move_to_position(&list, param);
        }
        else if (func == 10)
        {
            int len = get_size(&list);
            printf("Array size is %d\n", len);
        }
        else if (func == 11)
        {
            int value = get_current_element(&list);
            printf("Current element is %d\n", value);
        }
        else if (func == 12)
        {
            append(&list, param);
            printf("Appended %d at the end\n", param);
        }
        else if (func == 13)
        {
            clear(&list);
            printf("Cleared list");
            printf("\n");
        }
        else
        {
            printf("Invalid function\n");
        }
        print_list(&list);
    }
    free_list(&list);
    printf("Program terminated\n");
    fclose(file);
    fclose(fout);
    return 0;
}