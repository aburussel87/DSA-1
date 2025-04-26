#include <iostream>
#include <cmath>
#include <cctype>
#include <string>

using namespace std;

class Stack {
private:
    int *array; // Dynamic array for stack
    int size;   // Current size of the stack
    int capacity; // Maximum capacity of the stack

public:
    Stack(int initialCapacity = 10) {
        capacity = initialCapacity;
        array = new int[capacity];
        size = 0;
    }

    ~Stack() {
        delete[] array; // Free dynamically allocated memory
    }

    void push(int value) {
        if (size >= capacity) {
            resize(capacity * 2); // Double the capacity
        }
        array[size++] = value; // Add the new element
    }

    int pop() {
        if (size == 0) {
            throw runtime_error("Stack underflow");
        }
        return array[--size]; // Remove and return the top element
    }

    int top() {
        if (size == 0) {
            throw runtime_error("Stack is empty");
        }
        return array[size - 1]; // Return the top element
    }

    bool isEmpty() {
        return size == 0; // Check if the stack is empty
    }

    void resize(int newCapacity) {
        int *newArray = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }
};

int value(int a, int b, char oprtr) {
    switch (oprtr) {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/':
            if (a == 0) {
                cout << "Error: Division by zero!" << endl;
                exit(1);
            }
            return b / a;
        case '^': return pow(b, a);
        default: return 0; // Handle unexpected operators
    }
}

int precedence(char oprtr) {
    if (oprtr == '+' || oprtr == '-') return 1;
    if (oprtr == '*' || oprtr == '/') return 2;
    if (oprtr == '^') return 3;
    return 0;
}

int evaluate(const string &s) {
    Stack operand; // Stack for operands
    Stack opertr; // Stack for operators
    int num = 0;
    bool readingNumber = false;

    for (char symbol : s) {
        if (isspace(symbol)) continue;

        if (isdigit(symbol)) {
            num = num * 10 + (symbol - '0'); // Build the multi-digit number
            readingNumber = true;
        } else {
            if (readingNumber) {
                operand.push(num); // Push the complete number onto the stack
                num = 0; // Reset num for the next number
                readingNumber = false;
            }

            if (symbol == '(') {
                opertr.push(symbol);
            } else if (symbol == ')') {
                while (!opertr.isEmpty() && opertr.top() != '(') {
                    int a = operand.pop();
                    int b = operand.pop();
                    char op = opertr.pop();
                    operand.push(value(a, b, op));
                }
                opertr.pop(); // Remove '('
            } else { // Operators
                while (!opertr.isEmpty() && precedence(opertr.top()) >= precedence(symbol)) {
                    int a = operand.pop();
                    int b = operand.pop();
                    char op = opertr.pop();
                    operand.push(value(a, b, op));
                }
                opertr.push(symbol);
            }
        }
    }

    if (readingNumber) {
        operand.push(num); // Push the last number onto the stack
    }

    while (!opertr.isEmpty()) {
        int a = operand.pop();
        int b = operand.pop();
        char op = opertr.pop();
        operand.push(value(a, b, op));
    }

    return operand.pop(); // Final result from the operand stack
}

int main() {
    string expr;
    cout << "Enter infix expression: ";
    getline(cin, expr);
    int result = evaluate(expr);
    cout << "Result: " << result << endl;
    return 0;
}
