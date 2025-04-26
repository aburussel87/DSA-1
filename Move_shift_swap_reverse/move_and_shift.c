#include "arraylist.h"
// #include "linkedlist.h"
#include <stdio.h>


int main()
{
    const char* input_filename= "books.txt";
    FILE *file = fopen(input_filename, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    
    int number_of_books;
    const int CAPACITY = 10;
    fscanf(file, "%d", &number_of_books);
    printf("number_of_books: %d\n", number_of_books);

    ArrayList books;
    init_arraylist(&books, CAPACITY);
    // LinkedList books;
    // init_linkedlist(&books);
    int i;
    for (i=0; i<number_of_books; i++)
    {
        int book_id;
        fscanf(file, "%d", &book_id);
        append(&books, book_id);
    }
    print_list(&books);
    printf("\n");


    int func, param;
    while (fscanf(file, "%d %d", &func, &param) == 2)
    {
        if (func == 1)
        {
            skip(&books);
            printf("skipped current element\n");
        }
        else if (func == 2)
        {
            int x = get_current_element(&books);
            move_and_shift(&books, param);
            printf("Moved %d to postion %d\n",x,param);
        }
        else if (func == 3)
        {
            int x = get_current_element(&books);
            discard(&books);
            printf("discarded %d\n",x);
        }
        else if(func == 4){
            int x = get_current_element(&books);
            int y = swap(&books,param);
            printf("swapped %d and %d\n",x,y);
        }
        else if(func == 5)
        {
            reverse(&books);
            printf("Reversed the list\n");
        }
        print_list(&books);
    }

    free_list(&books);
    fclose(file);
    return 0;
}