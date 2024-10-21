#include <algorithm>
#include <iostream>
#include <limits.h>
#include <cassert>
using namespace std;

int findSecondMax(int arr[], int size) {
    if (size < 2) return INT_MIN;

    int max_elem = max(arr[0], arr[1]);
    int second_max_elem = min(arr[0], arr[1]);

    for (int i = 2; i < size; i++) {
        if (arr[i] > max_elem) {
            second_max_elem = max_elem;
            max_elem = arr[i];
        } 
        else if (arr[i] > second_max_elem && arr[i] != max_elem) {
            second_max_elem = arr[i];
        }
    }

    if (second_max_elem == max_elem) return INT_MIN;

    return second_max_elem;
}

int main() 
{
    int arr[] = {1, 10, 5, 6, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    assert(findSecondMax(arr, size) == 8);

    int arr2[] = {10, 10, 10};
    size = sizeof(arr2) / sizeof(arr2[0]);
    assert(findSecondMax(arr2, size) == INT_MIN);

    return 0;
}
