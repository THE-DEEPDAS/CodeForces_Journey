// they celebrated most rainy day in summer
// now they want to celebrate not so rainy day
// n days in summer and we know each day's rain
// the day is not so rainy id x days before has more rain and y days after has more rain
// find earliest non rainy day
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> rain(n);
    for (int i = 0; i < n; i++) {
        cin >> rain[i];
    }

    for (int i = 0; i < n; i++) {
        bool valid = true;

        // Check x days before
        for (int j = max(0, i - x); j < i; j++) {
            if (rain[j] <= rain[i]) {
                valid = false;
                break;
            }
        }

        // Check y days after
        for (int j = i + 1; j <= min(i + y, n - 1); j++) {
            if (rain[j] <= rain[i]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            cout << i + 1 << endl; // Output 1-based index
            return 0;
        }
    }

    // According to problem constraints, this line should never be reached
    return 0;
}
