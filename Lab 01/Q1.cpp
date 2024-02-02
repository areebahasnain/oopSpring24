#include <iostream>

using namespace std;

bool isPrime(int num){
    if(num <= 1){
        return false;
    }
    for(int i= 2; i*i <= num; i++){
        if(num % i == 0){
        return false;
        }
    }
    return true;
}
int main() {
    int n;
    cout << "Enter a Number: ";
    cin >> n;
    if(isPrime(n)){
        cout << n << " is a prime number.\n";
    }
    else{
        cout << n << " is not a prime number";
    }
    
    return 0;
}
task1.cpp
Displaying task1.cpp.