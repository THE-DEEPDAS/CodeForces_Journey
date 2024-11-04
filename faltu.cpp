#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    int t = 10000;  // Maximum number of test cases
    ofstream outfile("testcases.txt"); // Create and open the file

    outfile << t << endl;  // Output the number of test cases

    for (int i = 0; i < t; i++) {
        outfile << 100000 << endl;  // Output the length of the array

        // Generate a list of n elements alternating between 100000 and -100000
        for (int j = 0; j < 100000; j++) {
            if (j % 2 == 0) {
                outfile << 100000 << " ";  // Alternating pattern starts with 100000
            } else {
                outfile << -100000 << " ";  // Alternates to -100000
            }
        }
        outfile << endl;  // Move to the next line after each test case
    }

    outfile.close(); // Close the file
    return 0;
}
