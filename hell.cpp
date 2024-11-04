#include <iostream>

using namespace std;

int main() {
    int t = 9999;  // Number of test cases
    int n = 10000; // Length of each array

    cout << t << endl;  // Output the number of test cases

    for (int i = 0; i < t; i++) {
        cout << n << endl;  // Output the length of the array

        // Generate a list of n elements alternating between 1 and -1
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                cout << 1 << " ";  // Alternating pattern starts with 1
            } else {
                cout << -1 << " ";  // Alternates to -1
            }
        }
        cout << endl;  // Move to the next line after each test case
    }

    return 0;
}
