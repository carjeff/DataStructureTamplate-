#include <iostream>
#include <vector>
using namespace std;
template <typename type>
void Swap(type &a, type &b)
{
    type temp;
    temp = a;
    a = b;
    b = temp;
}

//冒泡排序
template <typename type>
void BubbleSort(type &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                Swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//选择排序
template <typename type>
void SelectSort(type &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int temp = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[temp])
            {
                temp = j;
            }
        }
        if (temp != i)
        {
            Swap(arr[temp], arr[i]);
        }
    }
}

//快速排序
template <typename type>
int Partiton(type &arr, int left, int right)
{
    int temp = arr[left];
    int low = left; //定义 两个指针分别指向数组左边和右边
    int high = right;
    while (low < high)
    {
        while (low < high && arr[high] > temp)
            high--;
        arr[low] = arr[high];
        while (low < high && arr[low] < temp)
            low++;
        arr[high] = arr[low];
    }
    arr[low] = temp;
    return low;
}

template <typename type>
void QSort(type &arr, int left, int right)
{
    if (left < right)
    {
        int k = Partiton(arr, left, right);
        QSort(arr, left, k - 1);
        QSort(arr, k + 1, right);
    }
}

template <typename type>
void QuickSort(type &arr, int n)
{
    QSort(arr, 0, n - 1);
}

//堆排
template <typename type>
void HeapAdjust(type &arr, int n, int s)
{
    int i = s;
    while (i + i + 1 < n)
    {
        int j = i + i + 1;
        if (j + 1 < n && arr[j] < arr[j + 1])
        {
            j++;
        }
        if (arr[j] <= arr[i])
            break;
        else
        {
            Swap(arr[j], arr[i]);
            i = j;
        }
    }
    /*    for(int i =0; i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
*/
}

template <typename type>
void CreateHeap(type &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        HeapAdjust(arr, n, i);
    }
}

template <typename type>
void HeapSort(type &arr, int n)
{
    CreateHeap(arr, n);
    for (int i = n; i > 1; i--)
    {
        Swap(arr[0], arr[i - 1]);
        HeapAdjust(arr, i - 1, 0);
    }
}

//插入排序
template <typename type>
void InsertSort(type &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = i;
        for (int j = i - 1; j >= 0 && arr[temp] < arr[j]; j--)
        {
            Swap(arr[temp], arr[j]);
            temp = j;
        }
    }
}

//归并排序
template <typename type>
void MergeTwoArr(type &arr, int left, int mid, int right, type &temp)
{
    int i = left;
    int j = mid + 1;
    int index = left;
    //循环将小数放到temp中
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
        }
    }

    while (i <= mid)
        temp[index++] = arr[i++]; //将剩余左半序列放到temp中
    while (j <= right)
        temp[index++] = arr[j++]; //将剩余右半序列放到temp中

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

template <typename type>
void MergeSortRec(type &arr, int left, int right, type &temp)
{
    if (left != right)
    {
        int mid = (left + right) / 2;
        MergeSortRec(arr, left, mid, temp);
        MergeSortRec(arr, mid + 1, right, temp);
        MergeTwoArr(arr, left, mid, right, temp);
    }
}

template <typename type>
void MergeSort(type &arr, int n)
{
    type temp(arr);
    MergeSortRec(arr, 0, n - 1, temp);
}