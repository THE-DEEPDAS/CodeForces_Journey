//------------------------------------Libraries Included-------------------------------------------
#include <bits/stdc++.h>
using namespace std;
// External libraries for ordered sets and trees i.e Policy based Data Structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// Define an ordered set using PBDS that works in logirithmic time complexity
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
//-------------------------------------------------------------------------------------------------

typedef long long ll;

// Define constants
const ll INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<long long>::max();
const ll N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll lower_INF = 1e-9;

//----------------------------------------------------------------------------------------------------

float power_num(int n, int a, char c) {
    if(c == 'i'){
        ll res = 1;
    while (a) {
        if (a % 2) res *= n, a--;
        else n *= n, a /= 2;
    }
    return res;
    }else if(c == 'f'){
        return pow(n, a);
    }else{
        return -1;  // No Char typed
    }   
}

bool fast_prime(ll a) {
    if (a != 2 && a % 2 == 0 || a < 2) return false;
    for (ll i = 3; i * i <= a; i += 2)
        if (a % i == 0) return false;
    return true;    
}

bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1));
}

ll gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

ll ask_std(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    ll ans(0);
    cin >> ans;
    return ans;
}

//----------------------------------------------------------------------------------------------------

ll MSBPosition(ll N) {
    ll msb_p = -1;
    while (N) {
        N = N >> 1;
        msb_p++;
    }
    return msb_p;
}

ll findBitwiseOR(ll L, ll R) {
    if (L == R) return L;

    ll res = 0;
    ll msb_p1 = MSBPosition(L);
    ll msb_p2 = MSBPosition(R);

    while (msb_p1 == msb_p2) {
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

ll findBitwiseXOR(ll L, ll R) {
    if (L == R) return 0;

    ll res = 0;
    ll msb_p1 = MSBPosition(L);
    ll msb_p2 = MSBPosition(R);

    while (msb_p1 == msb_p2) {
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
ll mod_power(ll n, ll a, ll p) {
    ll res = 1;
    while (a) {
        if (a % 2) res = (res * n) % p, a--;
        else n = (n * n) % p, a /= 2;
    }
    return res;
}

// assumes b is prime then uses fermat's little theorem
ll mod_mul_inverse(ll a, ll b) {   
    return mod_power(a, b - 2, b);
}

// calculates n! mod m
ll factorial_mod(ll n, ll m){
    long long x = 1;
    for (int i = 2; i <= n; i++) {
        x = (x*i)%m;
    }
    return x%m;
}

void SieveOfEratosthenes(ll n, vector<ll> &v) {
    vector<bool> prime(n + 1, true); 
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            v.push_back(p);
        }
    }
}

template<typename T> // For any data type
int binary_search(const vector<T>& v, T target) {
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid] == target) return mid;
        if (v[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // target not found
}

inline void fast_io(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

//----------------------------------------------------------------------------------------------------
// For large data sets as always time complexity is O(nlogn)
void heapify(std::vector<ll>& arr, ll n, ll i) {
    ll largest = i;
    ll left = 2 * i + 1;
    ll right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<ll>& arr) {
    ll n = arr.size();
    
    for (ll i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    
    for (ll i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) {
        arr[k++] = L[i++];
    }
    
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
//----------------------------------------------------------------------------------------------------

int main (){
    fast_io();
    // freopen("input.txt", "r", stdin);
    
    return 0;
}

/*
    Improvement Comments :-
    use (l+r) >> 1; to find the mid faster as it is in binary form
    use binary search to find the square root of a number faster by taking 1 and a very big limiting number
    the number of perfect squares till n is floor of squareroot of n always which is given by typecasting it with ll or int as ll(func)
    and r-l >= 2 and do more questions involving binary search
*/