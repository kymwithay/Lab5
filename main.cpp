#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "stacktype.h"

bool IsOpen(char symbol);
bool IsClosed(char symbol);
bool validSyntax(char symbol, char open_symbol);

int main()
{
    Stacktype stack1;
    for(int x = 0; x < 20; ++x)
    {
        stack1.Push((rand() % 100));
    }
    
    stack1.Print();
    stack1.sort();
    stack1.Print();
    
    
    
    bool does_match = true;
    char symbol;
    char open_symbol;
    Stacktype stack;
    
    ifstream infile;
    infile.open("infile.txt");
    infile.get(symbol);
    while(symbol != '\n' && does_match) 
    {
        if (IsOpen(symbol)) 
        {
            stack.Push(symbol);
        }
        else if (IsClosed(symbol)) 
        {
            if (stack.isEmpty()) 
            {
                does_match = false;

            } 
            else 
            {
                open_symbol = stack.Top();
                stack.Pop();
                does_match = validSyntax(symbol, open_symbol);
            }
        }
        infile.get(symbol);
    }
    if (does_match) 
    {
        cout << "This expression matches." << endl;
    } else {
        cout << "This expression does not match." << endl;
    }
    
    return 0;
}


bool IsOpen(char symbol) {
    if (symbol == '(' || symbol == '{' || symbol == '[') {
        return true;
    } else {
        return false;
    }
}

bool IsClosed(char symbol) {
    if (symbol == ')' || symbol == '}' || symbol == ']') {
        return true;
    } else {
        return false;
    }
}

bool validSyntax (char symbol, char open_symbol) {
    if ((open_symbol == '(' && symbol == ')') ||
        (open_symbol == '{' && symbol == '}') ||
        (open_symbol == '[' && symbol == ']')) {
        return true;
    } else {
        return false;
    }
}