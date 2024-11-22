// બધા માટે રામ રામ, ભગવાનનું નામ લો અને તમારું કાર્ય શરૂ કરો.

#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Fast I/O setup
struct FastIO
{
    FastIO()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fast_io_setup;

// Binary Search Function
int binary_search(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Custom Power Function (Efficient Modular Exponentiation)
ll power(ll base, ll exp, ll mod = 1e9 + 7)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Sieve of Eratosthenes for Prime Numbers
vector<int> sieve(int n)
{
    vector<int> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

// Factorization to Find Prime Divisors of a Number
vector<int> prime_factors(int n)
{
    vector<int> factors;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

// Square Root Calculation (Integer)
int integer_sqrt(int n)
{
    int left = 0, right = n, ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid * mid == n)
            return mid;
        if (mid * mid < n)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    // so plank of 60 to be divided into 18,21,25
    // so firstly n / 2 planks of 25, 25
    // then n / 2 planks of 21, 21, 18
    // now 21 and 25 done so 18 remaining are ceil(n / 2)
    // in each time we can get 3 18's so ceil(ceil(n / 2) / 3)
    // so now just add all of these
    // ll ans = (n / 2) + (n / 2) + (ll)ceil((ll)(ceil((double)n / 2)) / 3);
    ll ans = n + (ll)(ceil((double)n / 6));
    cout << ans << "\n";
}

/*
  -----     -----    -----    ----
 |     -   |        |        |    |
 |     -    -----    -----   |----
 |     -   |        |        |
  -----     -----    -----   |
*/