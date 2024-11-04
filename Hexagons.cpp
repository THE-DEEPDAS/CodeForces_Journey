// a hexagonal grid is a two-dimensional grid where each cell is a hexagon.
// radius of area = n affected by a magic spell, starting from a central hexagon.
// the task is to determine the number of hexagons that are within 'n' cells away from the central hexagon, including the central one itself.
// so pattern is 1 + 6 + 12 + 18 + 24

typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n;
    cin >> n;

    ll ans = 1;
    ans += 6 * (n * (n + 1) / 2);

    cout << ans << endl;
}