/* K230059 - AREEBA HASNAIN SHAIKH */
/* Task Description: Develop a recursive function named hasSubsetSum that accepts an integer 
array, the array’s size, and a target sum as input and returns a boolean indicating whether 
a subset with the specified sum exists. */

#include <iostream>

using namespace std;

bool hasSubsetSum(int arr[], int size, int targetSum) {

    if (targetSum == 0) return true;

    if (size == 0 || targetSum < 0) return false;

    return hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]) || 
           hasSubsetSum(arr, size - 1, targetSum);
}

int main() {
    int arr[] = {3, 14, 7, 12, 5, 2}; 
    int targetSum = 27; 

    cout << (hasSubsetSum(arr, 6, targetSum) ? "true" : "false") << endl;
    return 0;
}
