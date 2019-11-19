#include<iostream>
#include"SortTemplate.h"
#include<vector>
using namespace std;


int main()
{

	vector<int> arr1 = { 9, 7, 5, 3, 1, 10 };

	cout << "vector:" << endl;
	for (int i=0; i< arr1.size();i++)
		cout << arr1[i] << " ";
	cout << endl;
	HeapSort(arr1,arr1.size());
	//SelectSort(arr1,arr1.size());
	//BubbleSort(arr1,arr1.size());
	//QuickSort(arr1,arr1.size());
	for (int i =0;i<arr1.size();i++)
		cout << arr1[i] << " ";
	cout << endl;


return 0;

}