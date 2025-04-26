#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 100
using namespace std;

class Stack
{
private:
    char *array;
    int size;
    int capacity;

public:
    Stack()
    {
        array = new char[1];
        size = 0;
        capacity = 1;
    }
    Stack(int initialCapacity)
    {
        array = new char[initialCapacity];
        size = 0;
        capacity = initialCapacity;
    }
    ~Stack()
    {
        delete[] array; // Free dynamically allocated memory
    }
    void resize(int newCapacity)
    {
        char *newArray = new char[newCapacity]; // Allocate new array
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
        delete[] array; // Free old memory
        array = newArray;
        capacity = newCapacity;
    }
    void push(char x)
    {
        if (size >= capacity)
        {
            resize(capacity * 2);
           // cout << "resized the array from " << capacity << " to " << capacity / 2 << endl;
        }
        array[size++] = x;
    }
    char pop()
    {
        if (size == 0)
            return -1;
        if (size < 0.25 * capacity)
        {
            resize(capacity / 2);
            //cout << "resized the array from " << capacity * 2 << " to " << capacity << endl;
        }
        return array[--size];
    }
    char top()
    {
        if (size == 0)
            return -1;
        return array[size - 1];
    }
    int length()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0 ? true : false;
    }
    void clear()
    {
        delete[] array;
        array = new char[1];
        size = 0;
        capacity = 1;
    }
};
bool match_char(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    else if (a == '{' && b == '}')
        return true;
    else if (a == '[' && b == ']')
        return true;
    return false;
}

int isValid(char *s)
{
    Stack s1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
            continue;
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            s1.push(s[i]);
        }
        else if (s[i] == ']' || s[i] == '}' || s[i] == ')')
        {
            if (s1.isEmpty())
            {
                cout << "Invalid expression!!" << endl;
                s1.clear();
                return 0;
            }
            else
            {
                char temp = s1.pop();
                if (!match_char(temp, s[i]))
                {
                    cout << "Invalid expression" << endl;
                }
            }
        }
    }
    if (s1.isEmpty())
    {
        cout << "Valid Expression\n";
        s1.clear();
        return 1;
    }
    else
    {
        cout << "Invalid expression\n";
        s1.clear();
        return 0;
    }
}

int precedence(char a)
{
    int x;
    switch (a)
    {
    case '^':
        x = 3;
        break;
    case '*':
    case '/':
        x = 2;
        break;
    case '+':
    case '-':
        x = 1;
        break;
    default:
        x = 0;
        break;
    }
    return x;
}

char* toPost(char *s)
{
    char *post = new char[strlen(s)];
    Stack arr;
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(s); i++)
    {
        symbol = s[i];
        switch (symbol)
        {
        case '(':
            arr.push(s[i]);
            break;
        case ')':
            while ((next = arr.pop()) != '(')
            {
                post[j++] = next;
            }
            break;
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
            while (!arr.isEmpty() && precedence(arr.top()) >= precedence(symbol))
                post[j++] = arr.pop();
            arr.push(symbol);
            break;

        default:
            post[j++] = symbol;
        }
    }
    while (!arr.isEmpty())
        post[j++] = arr.pop();
    post[j] = '\0';
    cout<<"Postfix of the expression is: \n";
    printf("%s\n", post);
    arr.clear();
    return post;
}
int evaluate(char* s){
int b,c;
Stack a;
for(int i = 0; i<strlen(s); i++){
    char symbol = s[i];
    if(symbol >= '0' && symbol<='9'){
        a.push(symbol-'0');
    }else{
        c = a.pop();
        b = a.pop();
        switch(s[i]){
            case '+':
                    a.push(b+c);
                    break;
            case '-':
                    a.push(b-c);
                    break;
            case '*':
                    a.push(b*c);
                    break;
            case '/':
                    a.push(b/c);
                    break;
            case '^':
                    a.push(pow(b,c));
                    break;
        }
    }
}
return a.pop();
}
int main()
{
    cout << "Enter an infix expression: \n";
    char exp[MAX];
    gets(exp);
    int x = isValid(exp);
    if (!x)
    {
        cout << "enter valid infix expression\n";
        return 0;
    }
    char *post = toPost(exp);
    int y  = evaluate(post);
    cout<<"value of the expression is: "<<y<<endl;
    return 0;
}