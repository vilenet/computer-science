#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<int> &arr){

    for( auto it = arr.begin(); it != arr.end(); ++it){
        // Searching the upper bound, i.e., first
        // element greater than *it from beginning
        auto const insertion_point = upper_bound(arr.begin(), it, *it);

        // Shifting the unsorted part
        rotate(insertion_point, it, it + 1);
    }
}

void print(vector<int> arr){
   for( int elem : arr)
      cout << elem << " ";
   cout << endl;
}

int main()
{
    vector<int> arr = { 2, 1, 5, 3, 7 ,5 ,4, 6};
    insertionSort(arr);
    print(arr);

 }
