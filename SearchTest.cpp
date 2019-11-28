#include <iostream>
#include <vector>
#include "SearchTemplate.h"
using namespace std;
int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    //OrderSearch(arr1, 6, arr1.size());
    BinarySearch(arr1, 6, arr1.size());
    return 0;
}