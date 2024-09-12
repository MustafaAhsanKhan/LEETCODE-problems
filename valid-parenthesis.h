#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T* ptr;
    int capacity;
    int top;

    // Function to resize the stack when it's full
    void resize()
    {
        capacity *= 2;
        T* newPtr = new T[capacity];
        for(int i = 0; i <= top; ++i)
        {
            newPtr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newPtr;
    }

public:
    Stack(int size = 10)
    {
        capacity = size;
        ptr = new T[capacity];  // Allocate memory for the stack
        top = -1;               // Initialize top index
    }

    // Push an element onto the stack
    void push(T data)
    {
        if(top == capacity - 1)
        {
            resize();
        }
        ptr[++top] = data;
    }

    // Pop the top element from the stack
    T pop()
    {
        if(top == -1)
        {
            cout << "Stack underflow\n";
            return T();
        }
        return ptr[top--];
    }

    // Peek the top element without removing it
    T peek()
    {
        if(top == -1)
        {
            cout << "Stack is empty\n";
            return T();
        }
        return ptr[top];
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Destructor to release memory
    ~Stack()
    {
        delete[] ptr;
    }
};

class Solution {
public:

    bool isValid(string s)
    {
        Stack<char> stack;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '[' || s[i] == '{' || s[i] == '(')
            {
                stack.push(s[i]);
            }
            else if (s[i] == ']')
            {
                if(stack.peek() == '[')
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == '}')
            {
                if(stack.peek() == '{')
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ')')
            {
                if(stack.peek() == '(')
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }
};