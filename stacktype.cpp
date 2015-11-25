#include "stackType.h"

Stacktype::Stacktype() 
{
    top = -1;
}

void Stacktype::Push(int n) 
{
    if (isFull()) 
    {
        cout << "Error. Stack is full." << endl;
        return;
    }

    top++;
    arr[top] = n;
}

void Stacktype::Pop() 
{
    if (isEmpty()) 
    {
        cout << "Error. Stack is empty." << endl;
        return;
    }

    top--;
}

int Stacktype::Top() 
{
    return arr[top];
}

bool Stacktype::isEmpty() {
    if(top < 0)
    {
        return true;
    }
    return false;
}

bool Stacktype::isFull() {
    if(top >= 20)
    {
        return true;
    }
    return false;
}

void Stacktype::Print() {
    Stacktype stack2;
    while(!isEmpty()) {
        cout << Top() << " " ;
        stack2.Push(Top());
        Pop();
    }
    cout << endl;
    while(!stack2.isEmpty()) {
        Push(stack2.Top());
        stack2.Pop();
    }
}

void Stacktype::sort() {
    Stacktype stack2, stack3;
    stack3.Push(Top());
    Pop();
    while(!isEmpty()) {
        if(Top() < stack3.Top()) {
            stack3.Push(Top());
            Pop();
        } else {
            while(stack3.Top() < Top()) {
                stack2.Push(stack3.Top());
                stack3.Pop();
                if(stack3.isEmpty()) {
                    break;
                }
            }
            stack3.Push(Top());
            Pop();
            while(!stack2.isEmpty()) {
                stack3.Push(stack2.Top());
                stack2.Pop();
            }
        }
    }
    
    while(!stack3.isEmpty()) {
        stack2.Push(stack3.Top());
        stack3.Pop();
    }
    
    while(!stack2.isEmpty()) {
        Push(stack2.Top());
        stack2.Pop();
    }
    
    
    
}