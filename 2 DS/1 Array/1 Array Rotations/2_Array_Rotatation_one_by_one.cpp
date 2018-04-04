// Program for array rotation one by one
#include <iostream>
using namespace std;

void printArray(int arr[], int N){
  for(int i = 0; i < N; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

void leftRotatebyOne(int arr[], int N){

  int i, temp = arr[0];
  for(i = 0; i < N-1; ++i)
     arr[i] = arr[i+1];
  arr[i] = temp;
}

void leftRotate(int arr[], int k, int N){
  for (int i = 0; i < k; ++i)
    leftRotatebyOne(arr, N);
}

int main()
{
   int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   int N = sizeof(arr)/sizeof(arr[0]);
   leftRotate(arr, 2, N);
   printArray(arr, N);

   return 0;
}
