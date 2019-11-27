#include<iostream>
#include"Stack.h"
using namespace std;
int main(){
    Stack <int> a(10);
    a.Push(5);
    a.Push(10);
    a.Push(20);
    a.Print();
    a.Pop();
    int b = a.GetTop();
    cout<<b<<endl;
    Stack <int> c(100);
    c.Push(6);
    int d = c.GetTop();
    cout<<d<<endl;
    Stack<char> hh(10);
    hh.Push('(');
    hh.Push(' ');
    hh.Push(')');
    hh.Print();

    return 0 ;
}