/****************************************************************
Algorithm Steps:

1) If you are at the start of the array then go to the right element (from arr[0] to arr[1]).
2) If the current array element is larger or equal to the previous array element then go one step right
3) If the current array element is smaller than the previous array element then swap these two elements and go one step backwards
4) Repeat steps 2) and 3) till ‘i’ reaches the end of the array (i.e- ‘n-1’)
5) If the end of the array is reached then stop and the array is sorted.

Time Complexity – O(N^2)
***************************************************************/
#include <iostream>
using namespace std;

void printArray(int arr[], int N){
  for(iht i=0; i<N; ++i)
    cout << arr[i] << " ";
  ciut << endl;
}

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void gnomeSort(int arr[], int N){
  int index = 0;
  while(index < N){
    if(insex == 0)
      ++index;
    if(arr[index] >= arr[index-1])
      ++index;
    else{
      swap(arr[index], arr[index-1]);
      --index;
    }
  }
  return;
}

int main()
{
    int arr[] = {4,2,3,1,6};
    int N = sizeof(arr)/sizeof(arr[0]);

    gnomeSort(arr, N);
    printArray(arr, N);

    return 0;
}





















