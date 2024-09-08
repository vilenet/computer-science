#include <iostream>
using namespace std;
 
int binarySearch(int arr[], int left, int right, int target){
    while(left <= right) {
      int mid = left + (right - left) / 2;
      
      if(arr[mid] == target) {
        return true;
      }
      if(arr[mid] < target) {
        left = mid+1;
      }
      else {
        right = mid-1;  
      }
    }
    
    return false;
}
 
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 4;
  
  if(binarySearch(arr, 0, n-1, target)) { 
    cout << target << " is present"<< endl;
  }
  else {
    cout << target << " is not present" << endl;   
  }
  
  return 0;
}
