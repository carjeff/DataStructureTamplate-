#include <iostream>
#include "SortTemplate.h"
#include <vector>
using namespace std;

int main()
{

	vector<int> arr1 = {9, 7, 5, 3, 1, 10};

	cout << "vector:" << endl;
	for (int i = 0; i < arr1.size(); i++)
		cout << arr1[i] << " ";
	cout << endl;
	//HeapSort(arr1,arr1.size());   //堆排序
	//SelectSort(arr1,arr1.size()); //选择排序
	//BubbleSort(arr1,arr1.size());	//冒泡排序
	//QuickSort(arr1,arr1.size());	//快速排序
	//InsertSort(arr1,arr1.size()); //插入排序
	MergeSort(arr1, arr1.size()); //归并排序
	for (int i = 0; i < arr1.size(); i++)
		cout << arr1[i] << " ";
	cout << endl;

	return 0;
}