/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

inline double strikeRate(int runs, int balls) { return runs/balls * 100; }
inline double battingAverage(int runs, int outs) { return runs/outs; }

int main() {
    int balls, runs, outs;
    cout << "Enter number of balls: ";
    cin >> balls;
    cout << "Enter number of runs: ";
    cin >> runs;
    cout << "Enter number of outs: ";
    cin >> outs;

    cout << "Strike rate: " << strikeRate(runs, balls) << endl;
    cout << "Batting average: " << battingAverage(runs, outs) << endl;

    return 0;
}