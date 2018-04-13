//Binary Search (Iterative)

#include <iostream>
using namespace std;
 
int binarySearch(int arr[], int l, int r, int x){
    while(l <= r ){
      int mid = l + (r-l)/2;
      if(arr[mid] == x)  return mid;
      if(arr[mid]  < x)  l = mid+1;
      else               r = mid-1;  
    }
    return -1;
}
 
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  int x = 4;
  int k = binarySearch(arr, 0, n-1, x);
  if(k > -1) cout << "x is present at index " << k << endl;
  else       cout << "x is not present in arr[]" << endl;   
}

