#include <iostream>
#include"QueueLinkedList.h"
using namespace std;

class Stack
{
private:
    Queue list;
    //write your code here. Add additional private variables if necessary

public:
    // Constructor
    Stack()
    {
       
        //write your code here. Initialize additional private variables if necessary
    }
    Stack(int initialCapacity)
    {
        //write your code here. Initialize additional private variables if necessary
    }

    // Destructor
    ~Stack()
    {
        
    }

    
    // Push an element onto the stack
    void push(int x)
    {
        list.enqueue(x);
        //write your code here.
        //push the element onto the stack
    }

    // Remove and return the top element
    int pop()
    {
        if(list.length() == 0) return -1;
        int i = 1;
        while(i<list.length()){
            list.enqueue(list.dequeue());
            i++;
        }
        return list.dequeue();
       //write your code here. Check if the stack is empty and return -1 if it is.
       //pop the top element and return it
    }

    // Return the top element without removing it
    int top()
    {
        if(list.length() == 0) return -1;
        int i = 1;
        while(i<list.length()){
            list.enqueue(list.dequeue());
            i++;
        }
        int x = list.dequeue();
        list.enqueue(x);
        return x;
        //write your code here. Check if the stack is empty and return -1 if it is.
        //return the top element
    }

    // Return the number of elements in the stack
    int length()
    {
        return list.length();
        //write your code here. Return the number of elements in the stack
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return list.isEmpty();
        //write your code here. Return true if the stack is empty, false otherwise
    }

    // Clear the stack
    void clear()
    {
        list.clear();
        //write your code here. Clear the stack.
        
    }
};
