// birthday cake = n sided polygon numbered 1 to n clockwise
// bessie wants to give only triangle pieces(size doesn't matter)
// find max number of triangles she can give out
// she has choosen x vertices and we can choose y = 0 vertices for making diagonals
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll calc_dis(ll x, ll y, ll total){
    if(x <= y)
        return y - x;
    return total - x + y;
}

inline int nxt(int x, int n) { return x == n ? 1 : x + 1; }

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n, x, y;
        cin >> n >> x >> y;

        vector<ll> points(x);
        for (ll i = 0; i < x; i++) // Fixed to read only 'x' points
            cin >> points[i];

        sort(points.begin(), points.end());

        ll ans = max(0LL, x - 2); // Start with x - 2 triangles if x >= 3

        for (ll i = 0; i < x; i++){
            // Check if two consecutive points are 2 edges apart
            ans += (calc_dis(points[i], points[nxt(i + 1, x) - 1], n) == 2);
        }

        cout << ans << endl;
    }
}
