/*

######### Status - O
######### PLetter - A
######### Problem - Max Plus Size
######### Time - 16:00
######### Creator - shadowkiyo17

*/

/*

To efficiently and properly intended to run this code, type the following command in the terminal::

    g++-14 -std=c++17 -o2 -Wall -D_GLIBCXX_DEBUG -fsanitize=address -fsanitize=undefined -o a.out a.cpp
    time ./a.out

    OR

    g++-14 -std=c++11 -o2 -Wall code.cpp -o code
    time ./code

    (14) as my current version is 14.0.2
*/

/*

If input and output are in form of files, then use the following
                Or use for testing purposes

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

*/

/*

If want to use chrono lib for time of code execution with high accuracy

    #define clock(s) auto s = chrono::high_resolution_clock::now()
    #define time(start, stop) auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);cout << "Time" << duration.count() << "\n"

    clock(s); clock(st); time(s,st);

*/

/*

Future Includes :-

    Fenwick Trees
    Segment Trees
    Bit Masking
    Up solve
    More sofisticated algo's

Based on priority, importance and use cases!!!!!!!

*/

//------------------------------------Libraries Included-------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// // External libraries for ordered sets and trees i.e Policy based Data Structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// // Define an ordered set using PBDS that works in logirithmic time complexity
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//-------------------------------------------------------------------------------------------------

// Shorthand for common data types & typedef's
typedef long long ll;
typedef tuple<ll, ll, ll> tpll;
typedef pair<ll, ll> pll;
#define q(n, que) queue<n> que
#define pq(n, pque) priority_queue<n> pque
#define pqrev(n, pque) priority_queue<n, vector<n>, greater<n>> pque
#define st(n, stt) stack<n> stt
#define se(n, see) set<n> see
#define v(n, vec) vector<n> vec
#define mapstd(n, mm) map<n, ll> mm
#define umapstd(n, umm) unordered_map<n, ll> umm

// Define constants
const ll INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<long long>::max();
const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll lower_INF = 1e-9;

// Macros for loops
#define autofo(i, n) for (auto i : n)
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define rfo(i, n) for (ll i = n - 1; i >= 0; --i)
#define fi(i, l, r) for (ll i = l; i <= r; ++i)
#define rfi(i, l, r) for (ll i = l; i >= r; --i)

// Macros for input/output & other operations
#define in(n) \
    ll n;     \
    cin >> n
#define inn(n, k) \
    ll n;         \
    ll k;         \
    cin >> n >> k
#define innn(n, k, m) \
    ll n;             \
    ll k;             \
    ll m;             \
    cin >> n >> k >> m
#define in128(n) \
    __int_t n;   \
    cin >> n // Not always available and not always needed too!!!!
#define ins(s) \
    string s;  \
    cin >> s
#define check_modulo(a, b) \
    a = a % b;             \
    if (a < 0)             \
    a += b
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"
#define out(n) cout << n << "\n"
#define outln(n) cout << n << " "
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define sortarr(arr, n) sort(arr, arr + n)
#define inst(v, n, pos) v.insert(v.begin() + pos, n)
#define instcont(v, n, t, pos) v.insert(v.begin() + pos, t, n)
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define rr return
#define mp make_pair
//----------------------------------------------------------------------------------------------------

float power_num(int n, int a, char c)
{
    if (c == 'i')
    {
        ll res = 1;
        while (a)
        {
            if (a % 2)
                res *= n, a--;
            else
                n *= n, a /= 2;
        }
        return res;
    }
    else if (c == 'f')
    {
        return pow(n, a);
    }
    else
    {
        return -1; // No Char typed
    }
}

bool fast_prime(ll a)
{
    if (a != 2 && a % 2 == 0 || a < 2)
        return false;
    for (ll i = 3; i * i <= a; i += 2)
        if (a % i == 0)
            return false;
    return true;
}

bool isPowerOfTwo(unsigned int n)
{
    return n && !(n & (n - 1));
}

ll gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

ll ask_std(int l, int r)
{
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    ll ans(0);
    cin >> ans;
    return ans;
}

//----------------------------------------------------------------------------------------------------

ll MSBPosition(ll N)
{
    ll msb_p = -1;
    while (N)
    {
        N = N >> 1;
        msb_p++;
    }
    return msb_p;
}

ll findBitwiseOR(ll L, ll R)
{
    if (L == R)
        return L;

    ll res = 0;
    ll msb_p1 = MSBPosition(L);
    ll msb_p2 = MSBPosition(R);

    while (msb_p1 == msb_p2)
    {
        ll res_val = (1LL << msb_p1);
        res += res_val;
        L -= res_val;
        R -= res_val;
        msb_p1 = MSBPosition(L);
        msb_p2 = MSBPosition(R);
    }

    res += (1LL << (max(msb_p1, msb_p2) + 1)) - 1;

    return res;
}

ll findBitwiseXOR(ll L, ll R)
{
    if (L == R)
        return 0;

    ll res = 0;
    ll msb_p1 = MSBPosition(L);
    ll msb_p2 = MSBPosition(R);

    while (msb_p1 == msb_p2)
    {
        ll res_val = (1LL << msb_p1);
        L -= res_val;
        R -= res_val;
        msb_p1 = MSBPosition(L);
        msb_p2 = MSBPosition(R);
    }

    res += (1LL << (max(msb_p1, msb_p2) + 1)) - 1;

    return res;
}

//----------------------------------------------------------------------------------------------------

// Finds the mod of n^a, given p for very large exponents efficiently
ll mod_power(ll n, ll a, ll p)
{
    ll res = 1;
    while (a)
    {
        if (a % 2)
            res = (res * n) % p, a--;
        else
            n = (n * n) % p, a /= 2;
    }
    return res;
}

// assumes b is prime then uses fermat's little theorem
ll mod_mul_inverse(ll a, ll b)
{
    return mod_power(a, b - 2, b);
}

// calculates n! mod m
ll factorial_mod(ll n, ll m)
{
    long long x = 1;
    for (int i = 2; i <= n; i++)
    {
        x = (x * i) % m;
    }
    return x % m;
}

void SieveOfEratosthenes(ll n, vector<ll> &v)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            v.push_back(p);
        }
    }
}

template <typename T> // For any data type
int binary_search(const vector<T> &v, T target)
{
    int left = 0, right = v.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] == target)
            return mid;
        if (v[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // target not found
}

inline void fast_io()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

//----------------------------------------------------------------------------------------------------
// For large data sets as always time complexity is O(nlogn)
void heapify(std::vector<ll> &arr, ll n, ll i)
{
    ll largest = i;
    ll left = 2 * i + 1;
    ll right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<ll> &arr)
{
    ll n = arr.size();

    for (ll i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, n, i);
    }

    for (ll i = n - 1; i >= 0; --i)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
//----------------------------------------------------------------------------------------------------

// void solve() {
//     in(n);
//     vector<pair<ll, ll>> vv;
//     ll mx1(0);
//     ll mx2(0);
//     fo(i, n){
//         ll x(0);
//         cin >> x;
//         pll p;
//         p.ff = x;
//         p.ss = i;
//         vv.pb(p);
//     }
//     rsrt(vv);
//     ll ans(0);
//     if(vv[0].ss%2 == 0){
//         ans = vv[0].ff;
//         if(n%2 == 0){
//             ans += n/2;
//         }else{
//             ans += n/2 + 1;
//         }
//         out(ans);
//     }
//     else{
//         ll s1(0);
//         ll s2(0);
//         ll i(1);
//         while(i<n){
//             if(vv[i].ss%2 == 0){
//                 s1 = vv[i].ff;
//                 if(n%2 == 0){
//                     s1 += n/2;
//                 } else{
//                     s1 += n/2 + 1;
//                 }
//                 break;
//             }else{
//                 continue;
//             }
//             i++;
//         }
//         s2 = vv[0].ff + n/2;
//         if(s1 > s2){
//             out(s1);
//         }else{
//             out(s2);
//         }
//     }
// }

void solve()
{
    in(n);
    ll mx1(0);
    ll mx2(0);
    fo(i, n)
    {
        ll x(0);
        cin >> x;
        if (mx1 < x)
        {
            mx1 = x;
        }
        if (mx2 < x && i % 2 == 0)
        {
            mx2 = x;
        }
    }
    ll ans(0);
    if (mx1 == mx2)
    {
        ans = mx1;
        if (n % 2 == 0)
        {
            ans += n / 2;
        }
        else
        {
            ans += n / 2 + 1;
        }
    }
    else
    {
        ll s1(0);
        ll s2(0);
        s1 = mx1 + (n / 2);
        s2 = mx2;
        if (n % 2 == 0)
        {
            s2 += n / 2;
        }
        else
        {
            s2 += n / 2 + 1;
        }
        if (s1 > s2)
        {
            ans = s1;
        }
        else
        {
            ans = s2;
        }
    }
    out(ans);
}

int main()
{
    fast_io();
    // freopen("input.txt", "r", stdin);
    in(t);
    while (t--)
    {
        solve();
    }
    return 0;
}

/*

    Author's Words :-

    If u copy this code, remember to write the authors name "shadowkiyo17"
    Pls Make your own cp temepate due to copyright strikes during live contest solving !!!!!!!

    Improvement Comments :-


*/