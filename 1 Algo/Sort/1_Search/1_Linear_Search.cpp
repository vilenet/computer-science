//Linear Search

#include <iostream>
using namespace std;
 
int search(int arr[], int x, int n){
    for(int i=0; i<n; i++)
      if(arr[i] == x)
        return i;
    return -1;
}
 
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  int x = 4;
  int k = search(arr, x, n);
  if(k > -1) cout << "x is present at index " << k << endl;
  else       cout << "x is not present in arr[]" << endl;   
}

