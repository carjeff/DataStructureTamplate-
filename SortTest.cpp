#include<iostream>
#include"SortTemplate.h"
#include<vector>
#include<array>
using namespace std;


int main()
{

	// ²âÊÔvector
	vector<int> arr1 = { 9, 7, 5, 3, 1 };

	cout << "vector:" << endl;
	for (auto i : arr1)
		cout << i << " ";
	cout << endl;

	for (auto i : QuickSort(arr1, arr1.size()))
		cout << i << " ";
	cout << endl;

	// ²âÊÔarray
	array<double, 5> arr2 = {1.1, 2.2, 4.4, 3.3, 5.5};

	cout << "array:" << endl;
	for (auto i : arr2)
		cout << i << " ";
	cout << endl;

	for (auto i : QuickSort(arr2, arr2.size()))
		cout << i << " ";
	cout << endl;
    return 0;
}