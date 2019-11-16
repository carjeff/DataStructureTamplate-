#include<iostream>
using namespace std;

template<typename type>
class Stack{
    private:
        int top;//定义栈顶指针
        type *elements; //栈
        int maxsize; //栈的最大容量
    public:
        //初始化栈
        Stack(int n):top(-1),maxsize(n){
            elements = new type[maxsize];
            if(elements == NULL){
                cout<<"Memory allocation failed!"<<endl;
                exit(-1);
            }
        }
        ~Stack(){
            delete[] elements;
        }
        //定义栈操作方法：入栈，出栈，获取栈顶元素，打印，清空栈，判断栈空，判断栈满
        void Push(const type item);
        type Pop();
        type GetTop();
        void Print();
        void Empty(){
            top = -1;
        }
        bool IsEmpty(){
            return top == -1;
        }
        bool IsFull(){
            return top == maxsize-1;
        }
};

template<typename type> void Stack<type>::Push(const type item)
{
    if (IsFull())
    {
        cout<<"The stack is full!"<<endl;
    }
    top++;
    elements[top] = item;

} 

template<typename type> type Stack<type>::Pop()
{
    if(IsEmpty())
    {
        cout<<"The Stack is empty!"<<endl;
        exit(-1);
    }
    return elements[top--];
}

template<typename type> type Stack<type>::GetTop()
{
    if(IsEmpty())
    {
        cout<<"The stack is empty!"<<endl;
        exit(-1);
    }
    return elements[top];

}
template<typename type> void Stack<type>::Print()
{
    int move = top;
    cout<<"Top=>";
    while (move!=-1)
    {
        cout<<elements[move--]<<"=>";
    }
    cout<<"Bottom"<<endl;
    
}