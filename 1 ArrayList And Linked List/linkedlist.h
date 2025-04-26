#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


typedef struct
{
    // add Node* head, tail, current_position and other necessary fields here
    Node* head;
    Node* tail;
    Node* current;
} LinkedList;


void init_linkedlist(LinkedList *list)
{
    
    // initialize head, tail with null
    list->head = NULL;
    list->tail = NULL;
    list->current= NULL;
}

int get_current_position(LinkedList *list);
void clear(LinkedList *list)
{
    // if(list->head == NULL) {
    //     printf("Empty list\n");
    // }
    // Node* temp = list->head;
    // while (temp!=NULL){
    //     Node* t  = temp->next;
    //     free(temp);
    //     temp = t;
    // }
    // list->head = NULL;
    // list->tail = NULL;

    if(list->head == nullptr){
        return ;
    }
    Node* temp = list->head;
    while(temp!= NULL && temp->next != nullptr){
        temp = temp->next;
        free(temp->prev);
    }
    if(temp != nullptr){
        free(temp);
    }
    list->head = NULL;
    list->current = NULL;
    list->tail = NULL;
    // traverse the list and free each node
    // set head and tail to null
}


int get_size(LinkedList *list)
{
    int c = 0;
    Node* temp = list->head;
    while(temp!=NULL){
        c++;
        temp = temp->next;
    }
    return c;
}


void append(LinkedList *list, int value)
{
     Node *n = (Node*)malloc(sizeof(Node));
     if(n == NULL){
        printf("Invalid memory allocation!!\n");
        return ;
     }
    n->data = value;
    n->next = NULL;
    n->prev = NULL;
     if(list->head == NULL){
        list->head= n;
        list->tail = n;
        list->current = n;
     }else {
        n->prev = list->tail;
        list->tail->next = n;
        list->tail = n;
     }
}


void insert(LinkedList *list, int value)
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = value;
    n->prev = NULL;
    n->next  = NULL;
    if(list->head ==NULL){
        list->head = n;
        list->tail = n;
        list->current  = n;
    }else if(list->current==list->head){
        n->next = list->head;
        list->head->prev=n;
        list->head = n;
        list->current = n;
    }
    else{
        n->next = list->current;
        n->prev = list->current->prev;
        list->current->prev->next=n;
        list->current->prev = n;
        list->current=n;
    }
    
}


int remove_at_current(LinkedList *list)
{
    int x;
    if(list->current==NULL){
        printf("The list is empty\n");
        return __INT_MAX__;
    }
     x = list->current->data;
    if(list->current==list->head){
        if(list->head->next==NULL){
            free(list->head);
            list->head = list->tail = list->current = NULL;
            return x;
        }
        list->head = list->head->next;
        free(list->current);
        list->head->prev = NULL;
        list->current = list->head;
    }else if(list->tail==list->current){
        list->tail = list->tail->prev;
        free(list->current);
        list->current = list->tail;
        list->tail->next = NULL;
    }else{
        Node* temp= list->current;
        list->current->prev->next=list->current->next;
        list->current->next->prev=list->current->prev;
        list->current = list->current->next;
        free(temp);
    }

    // consider the case when current code is at the begining or at the end
    return x;
}


int find(LinkedList *list, int value)
{
    // traverse the list and return the position of the value
    int c = 0;
    Node* temp = list->head;
    while(temp != NULL){
        if(temp->data == value){
            break;
        }else {
            temp = temp->next;
            c++;
        }
    }
    if(temp == NULL) return -1;
    else return c;
}


void move_to_start(LinkedList *list)
{
    if(list->head==NULL){
        printf("lIst is empty\n");
    }else if(list->current==list->head){
        printf("its already at start\n");
    }else{
        list->current=list->head;
    }
}


void move_to_end(LinkedList *list)
{
    if(list->head==NULL){
        printf("lIst is empty\n");
    }else if(list->current==list->tail){
        printf("its already at the end\n");
    }else{
        list->current=list->tail;
    }
}


void prev(LinkedList *list)
{
    if(list->head==NULL){
        printf("List is empty\n");
    }else if(list->current==list->head){
        printf("Invalid position\n");
    }else{
         int x  = get_current_position(list);
    printf("moved current to %d from %d\n",x-1,x);
        list->current=list->current->prev;
       
}
}


void next(LinkedList *list)
{
    if(list->current==list->tail){
        printf("Invalid position\n");
    }else{
        int x  = get_current_position(list);
         printf("moved current to %d from %d\n",x+1,x);
        list->current=list->current->next;
    }
}

void move_to_position(LinkedList *list, int position)
{
    Node* temp = list->head;
    for(int i = 1;i<=position;i++){
        temp = temp->next;
    }
    int x = get_current_position(list);
    printf("Moved current from %d to %d\n",x,position);
    list->current = temp;
}


int get_current_position(LinkedList *list)
{
    if(list->head == NULL || list->current == NULL){
        printf("Empty list\n");
        return -1;
    }
   int c = 0;
    Node* temp = list->head;
    while(temp != NULL){
        if(temp == list->current){
            break;
        }
        temp  = temp->next;
        c++;
    }
    // traverse the list and stop when you are at the current position
    // return the position (integer)
    return c;
}

int get_current_element(LinkedList *list)
{
   if(list->current==NULL){
    printf("list is empty\n");
    return -1;
   }
    // return the value at the current position
    return list->current->data;
}


void print_list(LinkedList *list)
{
    if(list->head == NULL){
        printf("<  >\n");
        return;
    }
    printf("<  ");
    Node* temp = list->head;
    while(temp!=NULL){
        if(temp==list->current){
            printf("|");
        }
        printf("%d  ",temp->data);
        temp = temp->next;
    }
    printf(">\n");
}


void free_list(LinkedList *list)
{
    clear(list);
    // free each node in the list
}
