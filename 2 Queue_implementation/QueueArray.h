#include <iostream>
using namespace std;

class Queue
{
private:
    int *array;
    int first;
    int rear;
    int capacity;
    int size;
    // write your code here. Add additional private variables if necessary

public:
    // Constructor
    Queue()
    {
        array = new int[1];
        size = 0;
        first = -1;
        rear = -1;
        capacity = 1;
        // write your code here. Initialize additional private variables if necessary
    }
    Queue(int initialCapacity)
    {
        array = new int[initialCapacity]; // Allocate initial memory
        // write your code here. Initialize additional private variables if necessary
        size = 0;
        first = -1;
        rear = -1;
        capacity = initialCapacity;
    }

    // Destructor
    ~Queue()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array
        int j = first;
        int i;
        for (i = 0; i < size; i++,first++)
        {
            newArray[i] = array[j % capacity];
            j++;
        }
        // write your code here. Copy the elements from the old array to the new array

        delete[] array; // Free old memory
        array = newArray;
        // cout<<"Resized the array from "<<capacity<<" to "<<newCapacity<<endl;
        capacity = newCapacity;
        first = 0;
        rear = size - 1;
        // write your code here. Update the capacity and array pointers
    }

    // Enqueue an element onto the queue
    void enqueue(int x)
    {
        if (size >= capacity)
            resize(capacity * 2);
        if (first == -1)
        {
            array[++first] = x;
            rear = first;
            size++;
        }
        else
        {
            rear = (rear + 1) % capacity;
            array[rear] = x;
            size++;
        }
        // write your code here. Check if the array is full and resize if necessary.
    }

    // Remove and return the peek element
    int dequeue()
    {
        int x;
        if (size == 0)
        {
            return -1;
        }
        else if (size == 1)
        {
            x = array[first];
            first = rear = -1;
        }
        else
        {
            x = array[first];
            first = (first+1)%capacity;
        }
        size--;
        return x;
        // write your code here. Check if the stack is empty and return -1 if it is.
        // remove the peek element and return it
        // resize the array if necessary
    }

    // Return the peek element without removing it
    int peek()
    {
        return array[first];
        // write your code here. Check if the queue is empty and return -1 if it is.
        // return the peek element
    }

    // Return the number of elements in the queue
    int length()
    {
        return size;
        // write your code here. Return the number of elements in the queue
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return size == 0 ? true : false;
        // write your code here. Return true if the queue is empty, false otherwise
    }

    // Clear the queue
    void clear()
    {
        delete[] array;
        array = new int[1];
        capacity = 1;
        size = 0;
        first = rear = -1;
        // write your code here. Clear the queue. resize the array to 1
    }
    int* get_array(){
        return array;
    }
    Queue* clone(){
        Queue* a = new Queue;
        a->array = array;
        a->size = size;
        a->capacity = capacity;
        a->first = first;
        a->rear = rear;
        return a;
    }
};
