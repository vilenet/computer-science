// Program for array rotation "A Juggling Algorithm"
#include <iostream>
using namespace std;

void printArray(int arr[], int N){
  for(int i = 0; i < N; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

/*Fuction to get gcd of a and b*/
int gcd(int a, int b){
   if(b==0)
     return a;
   else
     return gcd(b, a%b);
}

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n){

  int i, j, k, temp;
  for (i = 0; i < gcd(d, n); ++i){
    /* move i-th values of blocks */
    temp = arr[i];
    j = i;
    while(1){
      k = j + d;
      if (k >= n)
        k = k - n;
      if (k == i)
        break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
  }
}

int main()
{
   int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   int N = sizeof(arr)/sizeof(arr[0]);
   leftRotate(arr, 2, N);
   printArray(arr, N);

   return 0;
}

