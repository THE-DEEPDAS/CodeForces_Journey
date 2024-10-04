/*

######### Problem - A Robin Helps
######### Time - 20:17
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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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
typedef queue<ll> qll;
typedef queue<string> qs;
typedef priority_queue<ll> pqll;
typedef priority_queue<string> pqs;
typedef stack<ll> stll;
typedef stack<string> sts;
typedef set<ll> setll;
typedef set<string> sets;
typedef tuple<ll, ll, ll> tpll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;

// Define constants
const ll INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<long long>::max();
const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;

// Macros for loops
#define autofo(i, n) for (auto i : n)
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define rfo(i, n) for (ll i = n - 1; i >= 0; --i)
#define fi(i, l, r) for (ll i = l; i < r; ++i)
#define rfi(i, l, r) for (ll i = l; i >= r; --i)

// Macros for input/output operations & other
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
#define inarr(arr, n)          \
    ll arr[n];                 \
    for (ll i = 0; i < n; ++i) \
    cin >> arr[i]
#define invec(v, n)            \
    vector<ll> v(n);           \
    for (ll i = 0; i < n; ++i) \
    cin >> v.at(i)
#define outarr(arr, n)         \
    for (ll i = 0; i < n; ++i) \
        cout << arr[i] << " "; \
    cout << "\n"
#define outarr2d(arr, m, n)           \
    for (ll i = 0; i < m; ++i)        \
        for (ll j = 0; j < n; ++j)    \
            cout << arr[i][j] << " "; \
    cout << "\n"
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
#define sort(v) sort(all(v))
#define sortrev(v) sort(allrev(v))
#define allarr(arr, n) arr, arr + n
#define sortarr(arr) sort(allarr(arr, n))
#define square(x) (x) * (x)
#define clock(s) auto s = chrono::high_resolution_clock::now()
#define time(start, stop)                                                      \
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); \
    cout << "Time" << duration.count() << "\n"
#define inst(v, n) v.insert(n);
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define rr return
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
    ll ans;
    cin >> ans;
    return ans;
}

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
    ll res = 0;
    ll msb_p1 = MSBPosition(L);
    ll msb_p2 = MSBPosition(R);

    while (msb_p1 == msb_p2)
    {
        ll res_val = (1 << msb_p1);
        res += res_val;
        L -= res_val;
        R -= res_val;
        msb_p1 = MSBPosition(L);
        msb_p2 = MSBPosition(R);
    }

    msb_p1 = max(msb_p1, msb_p2);
    for (ll i = msb_p1; i >= 0; i--)
    {
        ll res_val = (1 << i);
        res += res_val;
    }
    return res;
}

ll findBitwiseXOR(ll L, ll R)
{
    ll res = 0;
    ll msb_p1 = MSBPosition(L);
    ll msb_p2 = MSBPosition(R);

    while (msb_p1 == msb_p2)
    {
        ll res_val = (1LL << msb_p1);
        res ^= res_val; // Use XOR
        L -= res_val;
        R -= res_val;
        msb_p1 = MSBPosition(L);
        msb_p2 = MSBPosition(R);
    }

    ll msb_max = max(msb_p1, msb_p2);
    for (ll i = msb_max; i >= 0; i--)
    {
        ll res_val = (1LL << i);
        res ^= res_val; // Use XOR
    }

    return res;
}

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

void SieveOfEratosthenes(ll n, vll &v)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            v.eb(p);
}

map<ll, set<ll>> mp;

void dfs(ll root)
{
    if (mp[root].empty())
        return;
    for (auto it : mp[root])
    {
        mp[it].erase(root);
        dfs(it);
    }
}

void bfs(ll root)
{
    queue<ll> q;
    q.push(root);
    while (!q.empty())
    {
        ll tmp = q.front();
        q.pop();
        for (auto it : mp[tmp])
        {
            q.push(it);
            mp[it].erase(tmp);
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

// Debugging function
template <typename T>
void debug(const T &value)
{
    cerr << value << "\n";
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
//----------------------------------------------------------------------------------------------------

void solve()
{
    inn(n, k);
    inarr(arr, n);
    ll ans(0);
    ll r(0);
    fo(i, n)
    {
        if (arr[i] >= k)
        {
            r += arr[i];
        }
        if (arr[i] == 0 && r > 0)
        {
            ans++;
            r -= 1;
        }
    }
    out(ans);
}

int main()
{
    fast_io();
    clock(start);
    freopen("input.txt", "r", stdin);
    in(t);
    while (t--)
    {
        solve();
    }
    clock(stop);
    time(start, stop);
    return 0;
}

/*

    Author's Words :-

    If u copy this code, remember to write the authors name "shadowkiyo17"
    Pls Make your own cp temepate due to copyright strikes during live contest solving !!!!!!!
    Can take idea's from mine but make your own so that u also learn how to efficiently use it !!!!!!!

    Improvement Comments :-


*/