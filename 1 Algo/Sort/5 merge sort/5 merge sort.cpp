#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1){
        arr[k] = L[i];
        i++; k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2){
        arr[k] = R[j];
        j++; k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void merge_sort(int arr[], int l, int r)
{
    if (l < r){
        int m = l+(r-l)/2;

        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
void print(int arr[], int N){
    for(int i = 0; i < N; ++i)
       cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int N = sizeof(arr)/sizeof(arr[0]);

    cout << "Given array is \n";
    print(arr, N);

    merge_sort(arr, 0, N - 1);

    cout << "\nSorted array is \n";
    print(arr, N);

    cin.get();
}
