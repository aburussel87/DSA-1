#include <iostream>
using namespace std;

template <typename T>
class singly_linked_list
{
    typedef struct Node
    {
        Node *next;
        T value;
    };
    Node *head;
    int size;

public:
    singly_linked_list() : head(nullptr), size(0);
    ~singly_linked_list()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // reverse
    void reverse()
    {
        if (!head || !head->next)
        {
            return;
        }
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while (current)
        {
            next = current->next;
            current->next = prev;
            current = next;
            prev = current;
        }
        head = prev;
    }

    // cycle detection---> Floyd's tortoise and Hare Algorithm
    bool hasCycle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }

    // middle element
    Node *findMid()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        { // finds the first middle(if two middles are present)
            slow = slow->next;
            fast = fast->next->next;
        }
    }

    // Remove nth Node from the end
    void remove_nth(int n)
    {
        Node *dummy = new Node;
        dummy->value = 0;
        dummy->next = head;
        Node *first = dummy;
        Node *second = dummy;
        for (int i = 0; i <= n; i++)
        {
            first = first->next;
        }
        while (first)
        {
            first = first->next;
            second = second->next;
        }
        Node *toDel = second->next;
        second->next = toDel->next;
        delete toDel;
        head = dummy->next;
        delete dummy;
    }

    // Palindrome
    bool isPalindrome()
    {
        if (!head || !head->next)
        {
            return true; // An empty list or single-node list is always a palindrome
        }

        // Find the middle of the list
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        Node *prev = nullptr;
        Node *current = slow;
        while (current)
        {
            Node *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        // Compare the two halves
        Node *firstHalf = head;
        Node *secondHalf = prev; // This is now the head of the reversed second half
        bool isPalin = true;
        while (secondHalf)
        {
            if (firstHalf->value != secondHalf->value)
            {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Restore the list by reversing the second half back
        current = prev;
        prev = nullptr;
        while (current)
        {
            Node *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return isPalin;
    }
};

int main()
{

    return 0;
}