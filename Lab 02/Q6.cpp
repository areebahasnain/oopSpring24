/* K230059 - AREEBA HASNAIN SHAIKH */
/* Task Description: Create two recursive functions to calculate the Least Common Multiple (LCM)
and Greatest Common Divisor (GCD) of two numbers. */

#include <iostream>

using namespace std;

int hcf(int n1, int n2){
    if (n2 != 0)
       return hcf(n2, n1 % n2);
    else 
       return n1;
}

int lcm(int n1, int n2, int c) {
    if (not (c%n1) and not (c%n2)) return c;

    return lcm(n1, n2, c+1);
}

int main()
{
   int n1, n2;

   cout << "Enter two positive integers: ";
   cin >> n1 >> n2;

   cout << "H.C.F of " << n1 << " & " <<  n2 << " is: " << hcf(n1, n2) << endl;
   cout << "L.C.M of " << n1 << " & " <<  n2 << " is: " << lcm(n1, n2, 1);

   return 0;
}

