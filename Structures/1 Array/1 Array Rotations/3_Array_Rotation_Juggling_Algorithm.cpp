// Program for array rotation "A Juggling Algorithm"
#include <iostream>
using namespace std;

void printArray(int arr[], int N){
    for(int i = 0; i < N; i++)
      cout << arr[i] << " ";
    cout << endl;  
}
 
int gcd(int a,int b){
    if(b == 0) return a;
    else       return gcd(b, a%b);
}

void LeftRotate(int arr[], int d, int n){
   for(int i = 0; i < gcd(d,n); ++i){
     int temp = arr[i];
     int j = i;
     while(1){
       int k = j+d;
       if(k >= n) k = k-n;
       if(k == i) break;
       arr[j] = arr[k];
       j = k;
     }
     arr[j] = temp;
   }
}

int main()
{
  int arr[] = {1,2,3,4,5,6,7}; 
  int N = sizeof(arr)/sizeof(arr[0]);	
  LeftRotate(arr, 2, N);
  printArray(arr, N);
  
  return 0;
}
