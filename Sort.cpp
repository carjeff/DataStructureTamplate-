#include <iostream>
#include <vector>
#include "SortTemplate.h"
using namespace std;

int main()
{
    int a[100];
    int n, b;
    cout << "\nPlease input the number: " << endl;
    cin >> n;
    cout << "\nPlease input the value: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //HeapSort(a,n);   //堆排序
    //SelectSort(a,n); //选择排序
    BubbleSort(a, n); //冒泡排序
                      //QuickSort(a,n);	//快速排序
                      //InsertSort(a,n); //插入排序
                      //MergeSort(a, n);	//归并排序
    cout << "After sorting, the result is:  " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
