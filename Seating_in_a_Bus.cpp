// each row has n seats
// if no seat is occupied then sit anywhere else sit beside a filled seat
// n passangers boarded with array recording seat number
// did they follow the recommendation
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        ll n;
        cin >> n;

        vector<ll> seats(n);
        bool valid = true;

        for (ll i = 0; i < n; ++i) {
            cin >> seats[i];
        }

        set<ll> validSeats;
        validSeats.insert(seats[0]);
        validSeats.insert(seats[0] - 1);
        validSeats.insert(seats[0] + 1);

        for (ll i = 1; i < n; ++i) {
            if (validSeats.find(seats[i]) == validSeats.end()) {
                valid = false;
                cout << "NO" << endl;
                break;
            }

            validSeats.insert(seats[i]);
            validSeats.insert(seats[i] - 1);
            validSeats.insert(seats[i] + 1);
        }

        if (valid) {
            cout << "YES" << endl;
        }
    }
}