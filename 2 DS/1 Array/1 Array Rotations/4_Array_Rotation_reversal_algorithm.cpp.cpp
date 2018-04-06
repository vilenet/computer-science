// Reversal algorithm of array rotation
#include <iostream>
using namespace std;
 
void printArray(int arr[], int n){
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
} 
 
void rverese(int arr[], int start, int end){
    while (start < end){
        int temp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = temp;
    }
}
 
void leftRotate(int arr[], int d, int n){
    rverese(arr, 0, d-1);
    rverese(arr, d, n-1);
    rverese(arr, 0, n-1);
}
 
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 3;
 
    leftRotate(arr, d, n);
    printArray(arr, n);
     
    return 0;
}