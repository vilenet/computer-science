#include <iostream>
using namespace std;

void stoogeSort(int arr[], int first, int last){

   if(first >= last) return;

   // If first element is smaller than last, swap them
   if(arr[first] > arr[last])
      swap(arr[first], arr[last]);

   // If there are more than 2 elements
   if(last-first+1 > 2){

     int temp = (last-first+1)/3;
     // Recursively sort first 2/3 elements
     stoogeSort(arr, first, last-temp);
     // Recursively sort last 2/3 elements
     stoogeSort(arr, first+temp, last);
     // Recursively sort first 2/3 elements again to confirm
     stoogeSort(arr, first, last-temp);
   }
}

int main()
{
    int arr[] = {2, 4, 5, 3, 1};
    int N = sizeof(arr) / sizeof(arr[0]);

    stoogeSort(arr, 0, N-1);

    for (int i=0; i<N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
