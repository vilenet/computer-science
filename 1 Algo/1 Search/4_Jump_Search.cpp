//Jump Search
#include <iostream>
#include <math.h>    // sqrt()
#include <algorithm> // min()
using namespace std;
 
int jumpSearch(int a[], int n, int x){
    int prev=0, step=sqrt(n);
    while(a[min(step, n)-1] < x){
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    while(a[prev] < x){
        if (++prev == min(step, n)) return -1;
    }
    if (a[prev] == x) return prev;
 
    return -1;
}   
 
int main()
{
  int x = 5;    
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = jumpSearch(arr, n, x);
  if(k > -1) cout << "x is present at index " << k << endl;
  else       cout << "x is not present in arr[]" << endl;
  
}

