    // draw on n by m table
    //(r,c) -> cth cell on rth row
    // The tail is at (1, 1), body extends to (1, m), goes down 2 rows to (3, m), goes left to (3, 1) and so on.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // number of rows and number of cells

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            // print a row full of '#'
            for (int j = 0; j < m; ++j) {
                cout << '#';
            }
            cout << endl;
        } else if ((i + 1) % 4 == 0) {
            // print a row with '#' at the beginning
            if (m == 1) {
                cout << '#' << endl;
            } else {
                cout << '#';
                for (int j = 1; j < m; ++j) {
                    cout << '.';
                }
                cout << endl;
            }
        } else {
            // print a row with '#' at the end
            if (m == 1) {
                cout << '#' << endl;
            } else {
                for (int j = 0; j < m - 1; ++j) {
                    cout << '.';
                }
                cout << '#' << endl;
            }
        }
    }

}
