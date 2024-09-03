// we paint a n * m table with element on intersection of ith row and jth colum = i * j
// indexing = 1 based
// find kth largest number from the matrix
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, k;
    cin >> n >> m >> k;

    // Memory Limit Exceeded Solution
    // priority_queue<ll, vector<ll>, greater<ll>> pq;
    // for(int i=0; i<n; i++)
    //     for(int j=0; j<m; j++)
    //         pq.push((i + 1) * (j + 1));

    // for (ll i = 0; i < k - 1; i++){
    //     pq.pop();
    // }
    // cout << pq.top() << endl;

    // so we need to perform Binary Search
    ll left = 1, right = n * m;
    ll ans = 0;
    while(left <= right){
        ll mid = left + (right - left) / 2;
        ll count = 0;
        for(int i = 1; i <= n; i++)
            count += min(mid / i, m);
            
        if(count >= k){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << ans << endl;
}