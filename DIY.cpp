// બધા માટે રામ રામ, ભગવાનનું નામ લો અને તમારું કાર્ય શરૂ કરો.

#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Fast I/O setup
struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup;

// Binary Search Function
int binary_search(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Custom Power Function (Efficient Modular Exponentiation)
ll power(ll base, ll exp, ll mod = 1e9+7) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Sieve of Eratosthenes for Prime Numbers
vector<int> sieve(int n) {
    vector<int> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) is_prime[j] = 0;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}

// Factorization to Find Prime Divisors of a Number
vector<int> prime_factors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

// Square Root Calculation (Integer)
int integer_sqrt(int n) {
    int left = 0, right = n, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid * mid == n) return mid;
        if (mid * mid < n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    ll testcases;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        map<ll, vector<ll>> points;
        for (ll i = 0; i < n / 2; i ++){
            ll x, y;
            cin >> x >> y;

            points[x].push_back(y);
        }

        // ll max_area = INT_MIN;

        // for (auto it1 = points.begin(); it1 != points.end(); ++it1) {
        //     for (auto it2 = next(it1); it2 != points.end(); ++it2) {
        //         ll x1 = it1->first, x2 = it2->first;
        //         const vector<ll>& y1 = it1->second;
        //         const vector<ll>& y2 = it2->second;

        //         vector<ll> common_y;
        //         set_intersection(
        //             y1.begin(), y1.end(),
        //             y2.begin(), y2.end(),
        //             back_inserter(common_y)
        //         );

        //         if (common_y.size() >= 2) {
        //             for (size_t i = 0; i < common_y.size(); ++i) {
        //                 for (size_t j = i + 1; j < common_y.size(); ++j) {
        //                     ll height = abs(common_y[i] - common_y[j]);
        //                     ll width = abs(x1 - x2);
        //                     ll area = height * width;
        //                     max_area = max(max_area, area);
        //                 }
        //             }
        //         }
        //     }
        // }

        // // cout << max_area << '\n';
        // if(max_area == INT_MIN){
        //     cout << "NO\n";
        // }
        // else{
        //     cout << "YES\n";
        //     cout << max_area << "\n";
        // }

        // so what should be my approach
        // initial wrong approach was find the repeating x coordinates which occurs >= 2 times
        // take their corresponding y values and if they are forming a rectangle then calculate their area
        // compare the area with the maximum area found till now and update the answer accordingly
        // now the problem i face in this approach is that slopes of the rectangle's side we are considering 0 or infinity only
        // but it can be a tilted rectangle also, so to solve it correctly i devised the new approach
        // this is a brute force approach which takes 4 points and calculate slopes of the parallel lines
        // finally find the area and make the comparisions but this gives TLE
        // final approach: what we can do is that 
    }
}


/*
  -----     -----    -----    ----   
 |     -   |        |        |    |  
 |     -    -----    -----   |----   
 |     -   |        |        |       
  -----     -----    -----   |       
*/