#include <iostream>
using namespace std;

class Stack
{
private:
    int *array;
    int size;
    int capacity;
    //write your code here. Add additional private variables if necessary
public:
    // Constructor
    Stack()
    {
        array = new int[1]; 
        size = 0;
        capacity = 1;
        //write your code here. Initialize additional private variables if necessary
    }
    Stack(int initialCapacity)
    {
        array = new int[initialCapacity];
        size = 0; 
        capacity = initialCapacity;
         // Allocate initial memory
        //write your code here. Initialize additional private variables if necessary
    }

    // Destructor
    ~Stack()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array
        for(int i=0; i<size; i++){
            newArray[i] = array[i];
        }
        //write your code here. Copy the elements from the old array to the new array
        delete[] array; // Free old memory
        array = newArray; 
        capacity = newCapacity;
        //write your code here. Update the capacity and array pointers
    }

    // Push an element onto the stack
    void push(int x)
    {
        //write your code here. Check if the array is full and resize if necessary.
        //push the element onto the stack
        if(size>=capacity){
            resize(capacity*2);
            //cout<<"resized the array from "<<capacity<<" to "<<capacity/2<<endl;
        }
        array[size++] = x;
    }

    // Remove and return the top element
    int pop()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       //pop the top element and return it
       //resize the array if necessary
       if(size == 0) return -1;
       if(size < 0.25*capacity){
            resize(capacity/2);
            //cout<<"resized the array from "<<capacity*2<<" to "<<capacity<<endl;
        }
       return array[--size];

    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        //return the top element
    if(size == 0) return -1;
    return array[size-1];
    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
        return size;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        return size==0? true:false;
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack. resize the array to 1
        delete []array;
        array = new int[1];
        size = 0; 
        capacity = 1;    
    }
};
