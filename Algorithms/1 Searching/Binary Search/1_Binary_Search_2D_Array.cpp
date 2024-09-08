// Binary Search in 2D Array
#include <iostream>
using namespace std;
 
bool binarySearch(int *matrix, const int rows, const int cols, int target) {
    int left = 0;
    int right = rows * cols - 1;

    while(left <= right) {
      int mid = left + (right - left) / 2;

      //Convert linear index to 2D coordinates
      int midValue = matrix[mid / cols * cols + mid % cols];
      
      if (midValue == target) {
        return true;
      }
      else if (midValue < target) {
        left = mid + 1;
      }
      else {
        right = mid - 1;  
      }
    }
    
    return false;
}
 
int main()
{
    int target = 3;
    const int rows = 3;
    const int cols = 4;

    int matrix[rows][cols] = {
        {1,  3,  5,  7 },
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    if(binarySearch(&matrix[0][0], rows, cols, target)) { 
        cout << target << " is present"<< endl;
    }
    else {
        cout << target << " is not present" << endl;   
    }
  
    return 0;
}
