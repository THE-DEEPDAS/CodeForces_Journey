// We have integers from 1 to n. Can we put them into 2 sets such that 
// the HCF or GCD of the sum of elements in each set is greater than 1?
// If yes, print the 2 sets in new lines.
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

// Function to compute the GCD of two numbers
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    // For n = 1 or 2, it's impossible to divide into two sets with the required GCD.
    if (n == 1 || n == 2) {
        cout << "No" << endl;
    } 
    else {
        vector<int> s1, s2;  // Two sets to hold the elements
        ll sum1 = 0, sum2 = 0; // Sums of the two sets

        // Distribute the numbers from 1 to n into two sets:
        // Odd numbers go to s1, even numbers go to s2.
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum1 += i;  // Add odd numbers to sum1
                s1.push_back(i); // Add to set 1
            } 
            else {
                sum2 += i;  // Add even numbers to sum2
                s2.push_back(i); // Add to set 2
            }
        }

        // Check if the GCD of the two sums is greater than 1.
        if (gcd(sum1, sum2) > 1) {
            cout << "Yes" << endl;

            // Print the size and elements of the first set
            cout << s1.size() << " "; 
            for (int i = 0; i < s1.size(); i++) {
                cout << s1[i] << " ";
            }
            cout << endl;

            // Print the size and elements of the second set
            cout << s2.size() << " "; 
            for (int i = 0; i < s2.size(); i++) {
                cout << s2[i] << " ";
            }
            cout << endl;
        } 
        else {
            // If GCD is not greater than 1, print "No"
            cout << "No" << endl;
        }
    }

}
