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
    cout<<b;
    return 0 ;
}