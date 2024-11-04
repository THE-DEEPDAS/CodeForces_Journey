// size is n * m rectangle
// we want to keep flagstones of a * a size to cover a square
// it is feasible to cover more area than the quare
// find number of flagstones needed if sides of flagstones must be parallel to square
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n, m, a;
    cin >> n >> m >> a;

    ll sides_horizontal, sides_vertical;
    sides_horizontal = (n % a == 0) ? n / a : n / a + 1;
    sides_vertical = (m % a == 0) ? m / a : m / a + 1;
    ll total_flagstones = sides_horizontal * sides_vertical;
    cout << total_flagstones << endl;
}