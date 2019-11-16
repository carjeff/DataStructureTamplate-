#include<iostream>
#include"Vector.h"
using namespace std;

int main(){
    Vector<int> a(10);
    for (int i = 0; i < 10; i++)
    {
        a.Insert(i,i+1);
    }
    a.Print();
    a.Delete(2);
    a.Print();
    a.Insert(4,10);
    a.Print();
    a.Insert(6,100);
    a.Print();
    int b = a.Find(100);
    cout<<b;
    return 0;
}