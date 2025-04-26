#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#define MAX_CAPACITY 100 // Defines the maximum capacity of the heap

class MINHEAP
{
private:
    int heap[MAX_CAPACITY]; // Array to store heap elements
    int size;               // Current number of elements in the heap

    // Sifts up the node at index i to maintain heap property
    void siftUp(int i)
    {
        /**Write your code here**/
        int parent_pos = (i - 1) / 2;
        if (parent_pos >= 0 && heap[i] < heap[parent_pos])
        {
            std::swap(heap[i], heap[parent_pos]);
            siftUp(parent_pos);
        }
        return;
    }

    // Sifts down the node at index i to maintain heap property
    void siftDown(int i)
    {
        /**Write your code here**/
        int leftpos = 2 * i + 1;
        int rightpos = 2 * i + 2;
        // int max = heap[leftpos] > heap[rightpos] ? (heap[leftpos] > heap[i] ? leftpos : i) : (heap[rightpos] > heap[i] ? rightpos : i);
        int min;
        if (leftpos < size && heap[i] > heap[leftpos])
        {
            min = leftpos;
        }
        else
        {
            min = i;
        }
        if (rightpos < size && heap[min] > heap[rightpos])
        {
            min = rightpos;
        }
        if (min != i)
        {
            std::swap(heap[min], heap[i]);
            siftDown(min);
        }
        return;
    }

public:
    // Constructor initializes an empty heap
    MINHEAP() : size(0) {}

    // Inserts a new element x into the heap
    void insert(int x)
    {
        if (size == MAX_CAPACITY)
        {
            throw std::length_error("insert() called, but the heap is full.");
        }

        /**Write your code here**/
        heap[size++] = x;
        siftUp(size - 1);
    }

    // Returns the maximum element without removing it
    int findMin()
    {
        if (size == 0)
        {
            throw std::runtime_error("findMax() called, but the heap is empty.");
        }

        /**Write your code here**/
        return heap[0];
    }

    // Removes and returns the maximum element from the heap
    int extractMin()
    {
        if (size == 0)
        {
            throw std::runtime_error("extractMax() called, but the heap is empty.");
        }

        /**Write your code here**/
        if (size == 1)
        {
            size = 0;
            return heap[0];
        }
        int max = heap[0];
        size--;
        heap[0] = heap[size];
        siftDown(0);
        return max;
    }

    // Returns the number of elements in the heap
    int getSize()
    {
        /**Write your code here**/
        return size;
    }

    // Checks if the heap is empty. Returns true if the heap is empty, false otherwise.
    bool isEmpty()
    {
        /**Write your code here**/
        return size == 0;
    }

    // Increases the value of the element at index i to new_value
    void decreaseKey(int i, int newValue)
    {
        if (i < 0 || i >= size || heap[i] <= newValue)
        {
            throw std::invalid_argument("decreaseKey() called with invalid index or invalid new value.");
        }

        /**Write your code here**/
        heap[i] = newValue;
        siftUp(i);
    }

    // Deletes the element at index i
    void deleteKey(int i)
    {
        /**Write your code here**/
        if (i < 0 || i >= size)
        {
            throw std::invalid_argument("deletekey() called with invalid index.");
        }
        heap[i] = heap[--size];
        siftDown(i);
    }

    // Prints the heap's content to the output file
    void printHeap(std::ofstream &outfile)
    {
        /**Write your code here**/
        if (size == 0)
        {
            outfile << "Nothing to print\n";
            return;
        }
        for (int i = 0; i < size; i++)
        {
            outfile << heap[i] << " ";
        }
        outfile << "\n";
    }

    // Checkes whether the Max Heap property is preserved or not. Returns true if the Max Heap property is valid and returns false otherwise.
    bool isValidMINHEAP()
    {
        /**Write your code here**/
        for (int i = 0; i < (size - 1) / 2; i++)
        {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if ((l < size && heap[l] < heap[i]) || (r < size && heap[r] < heap[i]))
            {
                return false;
            }
        }
        return true;
    }
};

#endif