#include <iostream>
using namespace std;

class Stacktype
{
private:
    int arr[20];
    int top;
    
public:
    Stacktype();
    void Push(int n);
    void Pop();
    int Top();
    void Print();
    void sort();
    bool isEmpty();
    bool isFull();
};