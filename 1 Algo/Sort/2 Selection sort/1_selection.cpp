#include <iostream>
using namespace std;

void print(int arr[], int N){
    for(int i = 0; i < N; ++i)
       cout << arr[i] << " ";
    cout << endl;
} 

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(int arr[], const int N){
    int i, j, min_index;
    
    for(i = 0; i < N; ++i){
      min_index = i;
      
      for(j = i+1; j < N; ++j)
        if(arr[j] < arr[min_index])
          min_index = j;
          
      swap(&arr[min_index], &arr[i]);   
    }
}

int main()
{
   int arr[] = {4,3,0,1,2}; 
   int n = sizeof(arr)/sizeof(arr[0]);
   selection_sort(arr, n);
   print(arr, n);
   
   cin.get();
   return 0;
}




















