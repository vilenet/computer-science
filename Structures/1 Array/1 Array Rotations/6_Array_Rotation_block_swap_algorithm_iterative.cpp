// Iterativ Block swap algorithm of array rotation
// Function rotate(ar[], d, n) that rotates arr[] of size n by d elements.

#include <iostream>
using namespace std;
 
void printArray(int arr[], int n){
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
} 
 
void swap(int arr[], int begin, int end, int d){
   for(int i = 0, temp; i<d; i++)   {
     temp = arr[begin + i];
     arr[begin + i] = arr[end + i];
     arr[end + i] = temp;
}} 
 
 
void Rotate(int arr[], int d, int n){
  if(d == 0 || d == n) return;
  int i = d;
  int j = n-d;
  while(i != j){
    if(i < j){  //A < B
      swap(arr, d-i, d+j-i, i);  
      i -= j;
    }
    else{       //A > B
      swap(arr, d-i, d, j);
      i -= j;
    }
  }
  swap(arr, d-i, d, i);
}
 
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  Rotate(arr, 4, n);
  printArray(arr, n);
     
}