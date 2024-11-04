#include <iostream>
#include <cmath>
using namespace std;

double findMinimumN(long long k) {
    long long left = k;
    long long right = 2 * k;

    while (left < right) {
        long long mid = left + (right - left) / 2;
        double perfect_squares = sqrt(mid); // Calculate as double
        
        // Compare using double to maintain precision
        if (mid - perfect_squares < k) {
            left = mid + 1;
        } 
        else {
            right = mid;
        }
    }

    return left; // Return the found minimum n
}

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long k;
        cin >> k;
        
        // Calculate the minimum n and take the ceiling
        double result = findMinimumN(k);
        cout << ceil(result) << endl; // Output the ceiling of the result
    }

    return 0;
}
