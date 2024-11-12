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

void simulate(string &s, ll &x, ll& y){
    for(char c : s){
        if (c == 'N')
            y += 1;
        else if (c == 'S')
            y -= 1;
        else if (c == 'W')
            x -= 1;
        else
            x += 1;
    }
}

// bool check_if_reachable(string &s, ll start_x, ll start_y, ll target_x, ll target_y, ll threshold_x, ll threshold_y) {
//     ll x = start_x, y = start_y;
//     while (true) {
//         for (char move : s) {
//             // Check if we’ve reached the target
//             if (x == target_x && y == target_y) return true;

//             // Move according to the character
//             if (move == 'N') y += 1;
//             else if (move == 'S') y -= 1;
//             else if (move == 'E') x += 1;
//             else if (move == 'W') x -= 1;

//             // Check if we’ve exceeded the threshold in the quadrant direction
//             if ((target_x > 0 && target_y > 0) && (x > target_x + threshold_x || y > target_y + threshold_y)) return false;
//             if ((target_x > 0 && target_y < 0) && (x > target_x + threshold_x || y < target_y + threshold_y)) return false;
//             if ((target_x < 0 && target_y > 0) && (x < target_x + threshold_x || y > target_y + threshold_y)) return false;
//             if ((target_x < 0 && target_y < 0) && (x < target_x + threshold_x || y < target_y + threshold_y)) return false;
//         }
//     }
// }

int main() {
    ll testcases;
    cin >> testcases;

    for(ll testcase = 0; testcase < testcases; testcase++){
        ll n, a, b;
        cin >> n >> a >> b;

        string s;
        cin >> s;

        ll current_x = 0, current_y = 0, threshold_x = 0, threshold_y = 0;
        simulate(s, current_x, current_y);
        threshold_x = current_x;
        threshold_y = current_y;

        // now just go till x + threshold x and y + threshold y if (a, b) is in 1st quadrant
        bool printed = false;
        // if(a > 0){
        //     if(b > 0){
        //         while(current_x < a + threshold_x && current_y < b + threshold_y){
        //             // simulate but check if we have reached the location then print YES else NO
        //             if(printed)
        //                 break;
        //             for(char c : s){
        //                 if(current_x == a && current_y == b){
        //                     cout << "YES\n";
        //                     printed = true;
        //                     break;
        //                 }
        //                 else{
        //                     if(c == 'N') current_y += 1;
        //                     else if(c == 'S') current_y -= 1;
        //                     else if(c == 'E') current_x += 1;
        //                     else if(c == 'W') current_x -= 1;
        //                 }
        //             }
        //         }
        //     }
        //     else{
        //         while(current_x < a + threshold_x && current_y > b + threshold_y){
        //             // simulate but check if we have reached the location then print YES else NO
        //             if(printed)
        //                 break;
        //             for(char c : s){
        //                 if(current_x == a && current_y == b){
        //                     cout << "YES\n";
        //                     printed = true;
        //                     break;
        //                 }
        //                 else{
        //                     if(c == 'N') current_y += 1;
        //                     else if(c == 'S') current_y -= 1;
        //                     else if(c == 'E') current_x += 1;
        //                     else if(c == 'W') current_x -= 1;
        //                 }
        //             }
        //         }
        //     }
        // }
        // else{
        //     if(b > 0){
        //         while(current_x > a + threshold_x && current_y < b + threshold_y){
        //             // simulate but check if we have reached the location then print YES else NO
        //             if(printed)
        //                 break;
        //             for(char c : s){
        //                 if(current_x == a && current_y == b){
        //                     cout << "YES\n";
        //                     printed = true;
        //                     break;
        //                 }
        //                 else{
        //                     if(c == 'N') current_y += 1;
        //                     else if(c == 'S') current_y -= 1;
        //                     else if(c == 'E') current_x += 1;
        //                     else if(c == 'W') current_x -= 1;
        //                 }
        //             }
        //         }
        //     }
        //     else{
        //         while(current_x > a + threshold_x && current_y > b + threshold_y){
        //             // simulate but check if we have reached the location then print YES else NO
        //             if(printed)
        //                 break;
        //             for(char c : s){
        //                 if(current_x == a && current_y == b){
        //                     cout << "YES\n";
        //                     printed = true;
        //                     break;
        //                 }
        //                 else{
        //                     if(c == 'N') current_y += 1;
        //                     else if(c == 'S') current_y -= 1;
        //                     else if(c == 'E') current_x += 1;
        //                     else if(c == 'W') current_x -= 1;
        //                 }
        //             }
        //         }
        //     }
        // }

        current_x = 0, current_y = 0;
        for (ll i = 0; i < 100; i++){
            if(printed)
                break;
            for(char c : s){
                if(current_x == a && current_y == b){
                    cout << "YES\n";
                    printed = true;
                    break;
                }
                else{
                    if(c == 'N')
                        current_y++;
                    else if(c == 'S')
                        current_y--;
                    else if(c == 'W')
                        current_x--;
                    else
                        current_x++;
                }
            }
        }

            if (!printed)
                cout << "NO\n";
    }
}


/*
  -----     -----    -----    ----   
 |     -   |        |        |    |  
 |     -    -----    -----   |----   
 |     -   |        |        |       
  -----     -----    -----   |       
*/