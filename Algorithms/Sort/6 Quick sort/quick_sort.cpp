#include<iostream>
#include <algorithm>

int partition(int arr[], int low, int high){

	int pivot = arr[high];
	int i = (low - 1);

	for(int j = low; j <= high- 1; j++){
      if(arr[j] <= pivot){
        std::swap(arr[++i], arr[j]);
	  }
	}

	std::swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high){
	if (low < high)	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
	int arr[] = {10, 80, 30, 90, 40, 50, 70};
	int N = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, N-1);
	
	for (const auto& n : arr) {
        std::cout << n << " ";
    }

	return 0;
}














