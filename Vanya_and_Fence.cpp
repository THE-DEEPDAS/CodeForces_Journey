// vanya and friends each of height a[i] are walking past a fence of height h
// if any one's height = h, he/she needs to bend so they occupy width = 2 units
// normal person's width = 1 units
// find the minimum width of road so thay can cross togather
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, h;
    cin >> n >> h;

    ll width = 0;
    vector<ll> heights(n);
    for (ll i = 0; i < n; i++){
        cin >> heights[i];
        if(heights[i] > h){
            width += 2;
        }
        else
            width++;
    }

    cout << width << endl;
}