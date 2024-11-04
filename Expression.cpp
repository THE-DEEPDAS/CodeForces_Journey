// we have 3 numbers a , b and c
// we have to put 2 operations + and * between a, b and b , c
// find the max possible numbers
// we can add brackets if needed
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    ll ans = INT_MIN;
    // so we can do +,* then *,+ then (+),* then *,(+)
    // also we can try +,+ and *,*
    ans = max(ans, a + (b * c));
    ans = max(ans, (a * b) + c);
    ans = max(ans, a * (b + c));
    ans = max(ans, (a + b) * c);
    ans = max(ans, a + b + c);
    ans = max(ans, a * b * c);

    cout << ans << endl;
}