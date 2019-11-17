#include<iostream>
using namespace std;

template<typename type>
class Queue{
    private:
        int front;//定义头指针
        int rear;//定义尾指针
        type *elements;
        int maxsize;
    public:
        Queue(int n):top(0),rear(0),maxsize(n){
            elements = new type[maxsize];
            if(elements == NULL){
                cout<<"Memory allocation failed"<<endl;
            }
        }
}