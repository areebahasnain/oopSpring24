#include <iostream>
using namespace std;
 
int maxArea(int height[], int len)
{
    int area = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            area = max(area, min(height[j], height[i]) * (j - i));
        }
    }
    return area;
}
 
int main()
{
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(height) / sizeof(height[0]);
 
    cout << maxArea(height, n);
 
}