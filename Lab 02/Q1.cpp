/* K230059 - AREEBA HASNAIN SHAIKH */
/* Task Description: swap two numbers using recursive function */

#include <iostream>

using namespace std;

void recursiveSwap(int &a, int &b, int count) {  
    if (count == 0) {  
        return;  
    } else {  
        int temp = a;  
        a = b;  
        b = temp;  
        recursiveSwap(a, b, count-1);  
    }  
}  

int main() {
    int x, y;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Enter a number: ";
    cin >> y;    
    cout << "Before: x = " << x << " y = " << y << endl;  

    recursiveSwap(x, y, 1);
    cout << "After: x = " << x << " y = " << y << endl;  
    return 0;  
} 