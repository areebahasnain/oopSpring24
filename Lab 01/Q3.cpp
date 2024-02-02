#include <iostream>
using  namespace std;

int* findTarget(int* num, int n, int target) {
    int* arr = new int[2];
    bool found = false;

    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

            if (num[i] + num[j] == target) {
                arr[0] = i, arr[1] = j;
                found = true;
                break;
            }
        }
    }

    // If no solution is found, set both indices to -1
    if (!found) {
        arr[0] = arr[1] = -1;
    }

    return arr;
}

int main() {
    int nums[4] = {2, 7, 11, 15};
    int* arr = findTarget(nums, 4, 9);

    // Print the result
    if (arr[0] != -1 && arr[1] != -1) {
        cout << "[" << arr[0] << "," << arr[1] << "]" << endl;
        cout << "Because nums[" << arr[0] << "] + nums[" << arr[1] << "] == 9" << ", we return [" << arr[0] << "," << arr[1] << "]" << endl;

    } else {
        cout << "No solution found." << endl;
    }

    delete[] arr;

    return 0;
}
