#include <iostream>
#include <algorithm>

void quickSort(int arr[], int left, int right){
    if (left >= right) return;

    int pivot = arr[right];
	int i = left;
    int j = right - 1;

	while (i <= j) {
        while (i <= j && arr[i] < pivot) i++;
        while (i <= j && arr[j] > pivot) j--;

        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    std::swap(arr[i], arr[right]);

	quickSort(arr, left, i - 1);
	quickSort(arr, i + 1, right);
}

int main()
{
	int arr[] = {1, 8, 3, 9, 4, 5, 7};
	int N = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, N-1);
	
	for (const auto& n : arr){
		std::cout << n << " ";
	}

	return 0;
}














