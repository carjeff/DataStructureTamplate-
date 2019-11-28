#include <iostream>
using namespace std;

template <typename type>
class Queue
{
private:
    int head; //定义头指针
    int tail; //定义尾指针
    type *elements;
    int maxsize;

public:
    Queue(int n) : head(0), tail(0), maxsize(n)
    {
        elements = new type[maxsize];
        if (elements == NULL)
        {
            cout << "Memory allocation failed" << endl;
            exit(-1);
        }
    }
    ~Queue()
    {
        delete[] elements;
    }
    void In(type item); //进队列
    type Out();         //出队列
    bool IsEmpty()
    { //判断队空
        return head == tail;
    }
    bool IsFull()
    { //判断队满
        return (tail + 1) % maxsize == maxsize;
    }
    void Print();
};

template <typename type>
void Queue<type>::In(type item)
{
    if (IsFull())
    { //队尾入
        cout << "the queue is full!" << endl;
    }
    else
    {
        elements[tail] = item;
        tail = (tail + 1) % maxsize;
    }
}

template <typename type>
type Queue<type>::Out()
{
    if (IsEmpty())
    { //队头出
        cout << "the queue is empty" << endl;
    }
    else
    {
        type temp;
        temp = elements[head];
        head = (head + 1) % maxsize;
        return temp;
    }
}

template <typename type>
void Queue<type>::Print()
{
    for (int i = head; i < tail; i++)
    {
        cout << elements[i] << " ";
    }
    cout << endl;
}