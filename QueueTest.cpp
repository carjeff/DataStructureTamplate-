#include<iostream>
#include"Queue.h"
using namespace std;

int main(){
    Queue<int> a(10);
    a.In(1);
    a.In(4);
    a.Print();
    a.In(5);
    a.In(100);
    a.In(120);
    a.Print();
    a.Out();
    int c = a.Out();
    cout<<c<<" "<<endl;
    a.Print();

    return 0;
}