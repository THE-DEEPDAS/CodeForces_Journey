#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Global setup for fast I/O
struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup;

int main() {
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++) {
        int n;
        cin >> n;

        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pq.push(x);
        }

        while (pq.size() > 1) {
            int t1 = pq.top(); pq.pop();
            int t2 = pq.top(); pq.pop();
            pq.push((t1 + t2) / 2);
        }

        cout << pq.top() << endl;
    }
}