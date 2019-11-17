#include<iostream>
#include"List.h"
using namespace std;

int main(){
    list<int> a;
    a.Insert(1);
    a.Print();
    a.Insert(2);
    a.Insert(3);
    a.Print();
    int b = a.Length();
    cout<<b<<endl;
    int c = a.Find(2);
    cout<<c;
    a.Delete(1);
    a.Print();
    return 0;
}