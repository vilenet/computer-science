// Program for array rotation. METHOD 1 (Using temp array).
#include <iostream>
using namespace std;

void printArray(int arr[], int N){
    for(int i = 0; i < N; i++)
      cout << arr[i] << " ";
    cout << endl;  
}

 void rotate(int arr[], int d, int n){
	int *temp = new int[d];
    
  //1) Store d elements in a temp array
    for(int i = 0; i < d; i++)
      temp[i] = arr[i];  
  
  //2) Shift rest of the arr[]  
    for(int i = d; i < n; i++)
      arr[i-d] = arr[i];  
  
  //3) Store back the d elements  
    for(int i = 0; i < d; i++)
      arr[n-d+i] = temp[i]; 

    delete[] temp;  
 }

int main()
{
  const int N = 7;    
  int arr[N] = {1,2,3,4,5,6,7};
  rotate(arr, 2, N);
  printArray(arr, N);
 
}	
