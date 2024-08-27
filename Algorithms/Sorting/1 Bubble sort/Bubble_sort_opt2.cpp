// Optimized bubble sort v2
#include <iostream>
using namespace std;

void bubbleSort(int* nums, int size)
{
    while (size != 0) {
        int max_index = 0;

        for (int i = 1; i < size; i++) {
            if (nums[i - 1] > nums[i]) {
                int temp = nums[i - 1];
                nums[i - 1] = nums[i];
                nums[i] = temp;
                max_index = i;
            }
        }
        size = max_index;
    }
}

int main()
{
    int nums[] = { 5, 2, 4, 3, 0 };
    int size = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }

    cout << endl;

    bubbleSort(nums, size);

    for (int i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }

	return 0;
}
