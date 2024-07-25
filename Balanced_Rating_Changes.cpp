// n participants and ith participant is expecting ai change in rating
// balanced rating change means sum of all rating changes are 0
// now we need new ratings which is rounded of to nearest integer when divided by 2
// it should also be balanced
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<int> b(n);
    vector<int> to_floor;
    vector<int> to_ceil;
    ll sum = 0;

    // Compute the initial rounded ratings and their sum
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        float temp = a[i] / 2.0;
        int rounded = round(temp);
        b[i] = rounded;
        sum += rounded;

        // Track indices where we can adjust the value
        if (temp - floor(temp) == 0.5)
        {
            if (rounded == floor(temp))
                to_ceil.push_back(i);
            else
                to_floor.push_back(i);
        }
    }

    // Adjust the ratings if the sum is not zero
    if (sum != 0)
    {
        // Calculate the amount of adjustment needed
        int adjustments_needed = abs(sum);

        if (sum > 0)
        {
            // Decrease some values from ceil to floor
            for (int i = 0; i < adjustments_needed && !to_floor.empty(); i++)
            {
                int idx = to_floor.back();
                to_floor.pop_back();
                b[idx]--;
                sum--;
            }
        }
        else
        {
            // Increase some values from floor to ceil
            for (int i = 0; i < adjustments_needed && !to_ceil.empty(); i++)
            {
                int idx = to_ceil.back();
                to_ceil.pop_back();
                b[idx]++;
                sum++;
            }
        }
    }

    // Print the final ratings
    for (int integer : b)
    {
        cout << integer << endl;
    }
}