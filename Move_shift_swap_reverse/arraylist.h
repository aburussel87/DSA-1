#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int current;
    int size;
    int capacity;
} ArrayList;

void init_arraylist(ArrayList *list, int capacity)
{
    list->array = (int *)malloc(sizeof(int) * capacity);
    list->current = 0;
    list->size = 0;
    list->capacity = capacity;
    // dynamically allocate space for the array
    // initialize the size, capacity, and current position
}
void resize(ArrayList *list, int new_capacity)
{
    list->array = (int *)realloc(list->array, sizeof(int) * new_capacity);
    if (list->array == NULL)
    {
        printf("Memory reallocation failed!!\n");
        exit(1);
    }
    if(list->capacity<new_capacity){
       // printf("Resized array from %d to %d\n",list->capacity,new_capacity);
        list->capacity = new_capacity;
        return;
    }
   // printf("Resized array from %d to %d\n", list->capacity, new_capacity);
    list->capacity = new_capacity;
    // allocate space for new array with new_capacity
    // print log message
}
void print_list(ArrayList *list)
{
    if(list->size != 0 && (list->size <= 0.25*list->capacity)){
        resize(list,(list->capacity)/2);
    }
    printf("<  ");
    for (int i = 0; i < list->size; i++)
    {
        if (i == list->current)
        {
            printf("|");
        }
        printf("%d  ", list->array[i]);
    }
    printf(">");
    printf("\n");
}

void clear(ArrayList *list)
{
    while (list->size != 0)
    {
        list->array[--(list->size)] = 0;
    }
    list->current = 0;
}

int get_size(ArrayList *list)
{
    return list->size;
}


void append(ArrayList *list, int value)
{
    // call resize if necessary
    if ((list->size) >= list->capacity)
    {
        resize(list, 2 * list->capacity);
    }
    list->array[(list->size)++] = value;
    // add value to the end of the list
}

void insert(ArrayList *list, int value)
{
    if (list->size >= list->capacity)
    {
        resize(list, 2 * list->capacity);
    }
    for (int i = list->size; i > list->current; i--)
    {
        list->array[i] = list->array[i - 1];
    }
    list->array[list->current] = value;
    (list->size)++;
    // call resize if necessary
    // shift the elements to the right to make space
    // add value at the current position
}

int remove_at_current(ArrayList *list)
{
    if(list->size<1){
        printf("empty list\n");
        return __INT_MAX__;
    }
    int x = list->array[list->current];
    int i;
    for (i = list->current; i < (list->size) - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    (list->size)--;
    if(list->current==list->size){
        (list->current)--;
    }
    return x;
}

int find(ArrayList *list, int value)
{
    int found = -1;
    for (int i = 0; i < list->size; i++)
    {
        if (list->array[i] == value)
        {
            found = i;
            list->current = i;
            break;
        }
    }
    return found;
    // traverse the list and return the position of the value
    // return -1 if the value is not found
}

void move_to_start(ArrayList *list)
{
    if (list->size == 0)
        return;
    else
        list->current = 0;
    // consider the cases when the list is empty
}

void move_to_end(ArrayList *list)
{
    if (list->size == 0)
        return;
    list->current = list->size - 1;
}

void prev(ArrayList *list)
{
    if (list->current == 0)
    {
        printf("Invalid position!!\n");
        return;
    }
    if (list->size == 0)
        return;
   // printf("Moved current from %d to %d\n", list->current, list->current - 1);
    list->current = list->current - 1;
    // no change if the current position is at the start
}

void next(ArrayList *list)
{
    if ((list->current) + 1 == list->size)
    {
        printf("Invalid position!!\n");
        return;
    }
    if (list->size == 0)
        return;
   // printf("Moved current position form %d to %d\n", list->current, list->current + 1);
    list->current = list->current + 1;
}

void move_to_position(ArrayList *list, int position)
{
    if (position >= list->size || position < 0)
    {
        printf("Invalid position!!\n");
        return;
    }
    //printf("Moved current position to %d from %d\n", position,list->current);
    list->current = position;
}

int get_current_position(ArrayList *list)
{
    return list->current;
}

int get_current_element(ArrayList *list)
{
    return list->array[list->current];
}

void free_list(ArrayList *list)
{
    free(list->array);
    // free the array before terminating the program
}




//                                         New functions to move and shift,swap and reversing the list
//                          --------------------------------------------------------------------------------------




void skip(ArrayList* list){
    next(list);
}
void discard(ArrayList* list){
    remove_at_current(list);
}
void move_and_shift(ArrayList* list, int param){
    int ic = list->current;
    int x = get_current_element(list);
    discard(list);
    list->current = param;
    insert(list,x);
    if(param<ic) list->current = ic+1;
    list->current = ic;
}

int swap(ArrayList* list, int param){
    int x = get_current_element(list);
    int ic = get_current_position(list);
    list->current = param;
    int y = get_current_element(list);
    discard(list);
    if(param == list->size){
        append(list,x);
    }else insert(list,x);
    move_to_position(list,ic);
    discard(list);
    if(list->current==list->size) append(list,y);
    else insert(list,y);
    list->current = ic;
    return y;
}

void reverse(ArrayList* list){
        ArrayList l;
        init_arraylist(&l, 1);
        int ic = get_current_position(list);
        move_to_end(list);
        int len = list->size;
        for(int i = 0; i<len; i++){
            int x = remove_at_current(list);
            append(&l,x);
        }
        free_list(list);
        list->array = l.array;
        list->current = ic;
        list->size = l.size;
}
void rev(ArrayList *list){
     int pos = 0;
     int ic = list->current;
     move_to_end(list);
     for(int i = 0; i<list->size; i++){
        int x = list->array[list->current];
        remove_at_current(list);
        insert(list,pos);
        pos++;
     }
}
