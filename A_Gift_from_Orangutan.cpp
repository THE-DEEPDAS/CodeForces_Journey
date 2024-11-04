// we have an array of length n
// we construct 2 arrays b,c
// b = min(a1 to ai)
// c = max(a1 to ai)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void shift_right(vector<ll>& arr) {
    if (!arr.empty()) {
        ll last = arr.back();
        for (ll i = arr.size() - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }
}

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        ll max_element = a[n - 1];
        shift_right(a);
        a[0] = max_element;
        ll min_element = a[0], score = 0;

        for (ll i = 0; i < n; i++){
            min_element = min(a[i], min_element);
            score += max_element - min_element;
        }
        
        cout << score << endl;
    }
}
