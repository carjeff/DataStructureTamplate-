#include <iostream>
#include "SortTemplate.h"
using namespace std;
//顺序查找
template <typename type>
void OrderSearch(type &arr, int key, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
            break;
    }
    if (i < n)
    {
        cout << "Find the key:" << key << endl;
    }
    else
    {
        cout << "Can't find the key:" << key << endl;
    }
}
//二分查找
template <typename type>
int BinarySearch(type &arr, int key, int n)
{

    int position;
    int bottom = 0, top = n - 1;
    while (bottom <= top)
    {
        position = (bottom + top) / 2;
        if (arr[position] == key)
        {
            cout << "Find the key: " << key << endl;
            return 1;
        }
        if (arr[position] < key)
            bottom = position + 1;
        else
            top = position - 1;
    }
    cout << "Can't find the key: " << key << endl;
    return -1;
}