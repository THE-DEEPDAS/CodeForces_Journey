// n taps bring water in a continer, now ith one has temprature ti and can bring any amount 
// from 0 to ai water in the container 
// now we set ith tap to give xi amount of water, the resulting temp = sigma(xi * ti) / sigma(xi)
// if sigma(xi) is 0 , resulting temprature = 0
// we need final temprature = T, find max rate of water dropping
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

bool possible(ld total_flow, int n, int T, vector<ll>& max_rate, vector<ll>& temprature) {
    ld total_temp_sum = 0.0;
    ld total_water_sum = total_flow;

    for (int i = 0; i < n; i++) {
        if (temprature[i] < T){
            total_temp_sum += max_rate[i] * (T - temprature[i]);
        } 
        else if (temprature[i] > T){
            total_temp_sum -= max_rate[i] * (temprature[i] - T);
        }
    }
    return total_temp_sum >= 0.0;
}

int main() {
    int n, T;
    cin >> n >> T;

    vector<ll> max_rate(n);
    vector<ll> temprature(n);
    for (int i = 0; i < n; i++) cin >> max_rate[i];
    for (int i = 0; i < n; i++) cin >> temprature[i];

    ld left = 0.0, right = 1e18, ans = 0.0;
    while(left < right) { // Using a fixed number of iterations for binary search.
        ld mid = (left + right) / 2;
        if (possible(mid, n, T, max_rate, temprature)){
            ans = mid;
            left = mid;  
        } 
        else{
            right = mid; 
        }
    }
    cout << ans << endl;
}
