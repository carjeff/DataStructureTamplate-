#include<iostream>
#include<vector>
using namespace std;
template<typename type> void Swap(type &a, type &b){
    type temp;
    temp = a;
    a = b;
    b = temp;
}

//冒泡排序
template <typename type> type BubbleSort(type &arr, int n){
    for(int i= 0; i<n-1; i++){
        for(int j =0; j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                Swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;
}

//选择排序
template <typename type> type SelectSort(type &arr, int n){
    for(int i =0 ; i< n -1; i++){
        int temp = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[temp]){
                temp = j;
            }
        }
        if(temp!=i){
            Swap(arr[temp], arr[i]);
        }
    }
    return arr;
}

//快速排序
template <typename type> int Partiton(type &arr, int left, int right){
    int temp = arr[left];
    int low = left;  //定义 两个指针分别指向数组左边和右边
    int high = right;
    while (low < high)
    {
        while(low<high && arr[high] > temp) high--;
        arr[low]=arr[high];
        while(low<high && arr[low] < temp) low++;
        arr[high] = arr[low];
    }
    arr[low] = temp;
    return low;
}

template <typename type> void QSort(type &arr, int left, int right){
    if(left < right){
        int k = Partiton(arr, left, right);
        QSort(arr,left,k-1);
        QSort(arr,k+1,right);
    }
}

template <typename type> type QuickSort(type &arr, int n){
    QSort(arr, 0, n-1);
    return arr;
}

//堆排
template <typename type> void HeapAdjust(type &arr,int n, int s){
    int i = s;
    while(i+i+1<n){
        int j = i+i+1;
        if(j+1<n&&arr[j]<arr[j+1]){
            j++;
        }
        if(arr[j]<=arr[i]) break;
        else{
            Swap(arr[j],arr[i]);
            i=j;
            }
    }
/*    for(int i =0; i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
*/
}


template <typename type> void CreateHeap(type &arr, int n){
    for(int i = n/2-1 ; i>=0; i--){
        HeapAdjust(arr,n,i);
    }
}

template <typename type> void HeapSort(type &arr, int n ){
    CreateHeap(arr, n);
    for(int i =n; i>1;i--){
        Swap(arr[0], arr[i-1]);
        HeapAdjust(arr, i-1, 0);
    }
}