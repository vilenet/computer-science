// Recursive Block swap algorithm of array rotation
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
   }     
} 
 
void leftRotate(int arr[], int d, int n)
{ // A is d, B is n-d
  if(d==0 || d==n) return;
  
  if(d == n-d){ // If A is equal B  
    swap(arr, 0, n-d, d);   
    return;
  }  
  if(d < n-d){ // If A is shorter   
    swap(arr, 0, n-d, d);
    leftRotate(arr, d, n-d);   
  }  
  else{        // If B is shorter            
    swap(arr, 0, d, n-d);
    leftRotate(arr+n-d, 2*d-n, d); /*This is tricky*/
  }
} 
 
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  leftRotate(arr, 4, n);
  printArray(arr, n);
     
}
