// બધા માટે રામ રામ, ભગવાનનું નામ લો અને તમારું કાર્ય શરૂ કરો.

#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// Define an ordered set using PBDS that works in logarithmic time complexity
// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

typedef long long ll;
const ll INF = numeric_limits<ll>::max();
const ll INFLL = numeric_limits<long long>::max();
const ll MOD = 1e9 + 7;

// Fast I/O setup
inline void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// Find GCD of two numbers
template<typename T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Find LCM of two numbers
template<typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

// Check if a number is a power of two
template<typename T>
bool is_power_of_two(T n) {
    return n && !(n & (n - 1));
}


// Calculate MSB position
ll MSBPosition(ll N) {
    ll msb_p = -1;
    while (N) {
        N = N >> 1;
        msb_p++;
    }
    return msb_p;
}

// Find bitwise OR of two numbers
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

// Modular exponentiation
template<typename T>
T mod_power(T base, T exp, T mod) {
    T result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Modular multiplicative inverse
template<typename T>
T mod_mul_inverse(T a, T b) {
    return mod_power(a, b - 2, b);
}

// Heapify a subtree
void heapify(vector<ll>& arr, ll n, ll i) {
    ll largest = i;
    ll left = 2 * i + 1;
    ll right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Perform heap sort
void heapSort(vector<ll>& arr) {
    ll n = arr.size();
    for (ll i = n / 2 - 1; i >= 0; --i) heapify(arr, n, i);
    for (ll i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
// Merge two sorted subarrays
template<typename T>
void merge(vector<T>& arr, ll left, ll mid, ll right) {
    ll n1 = mid - left + 1;
    ll n2 = right - mid;
    vector<T> L(n1), R(n2);
    for (ll i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (ll j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];
    ll i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// MergeSort implementation
template<typename T>
void mergeSort(vector<T>& arr, ll left, ll right) {
    if (left < right) {
        ll mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Find bitwise XOR of two numbers
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

// Modular exponentiation
ll mod_power(ll n, ll a, ll p) {
    ll res = 1;
    while (a) {
        if (a % 2) res = (res * n) % p, a--;
        else n = (n * n) % p, a /= 2;
    }
    return res;
}

// Modular multiplicative inverse using Fermat's Little Theorem
ll mod_mul_inverse(ll a, ll b) {
    return mod_power(a, b - 2, b);
}

// Calculate factorial mod a number
ll factorial_mod(ll n, ll m) {
    ll x = 1;
    for (ll i = 2; i <= n; i++) {
        x = (x * i) % m;
    }
    return x % m;
}
// Perform binary search on a vector
template<typename T>
T binary_search(const vector<T>& arr, T target) {
    T left = 0, right = arr.size() - 1;
    while (left <= right) {
        T mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Calculate lleger square root
template<typename T>
T integer_sqrt(T n) {
    T left = 0, right = n, ans = -1;
    while (left <= right) {
        T mid = left + (right - left) / 2;
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

// Generate all primes up to n using the Sieve of Eratosthenes
template<typename T>
vector<T> sieve(T n) {
    vector<T> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (T i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (T j = i * i; j <= n; j += i) is_prime[j] = 0;
        }
    }
    vector<T> primes;
    for (T i = 2; i <= n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}

// Perform BFS on a graph
void bfs(ll start, const vector<vector<ll>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<ll> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        ll node = q.front(); q.pop();
        cout << node << ' ';
        for (ll neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Perform DFS on a graph
void dfs(ll node, const vector<vector<ll>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << ' ';
    for (ll neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

// Definition of the TreeNode class
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor for creating a new node
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Preorder tree traversal
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

// Inorder tree traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

// Postorder tree traversal
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
}

int main() {
    fast_io();
    ll testcases; cin >> testcases;
    while(testcases--) {
        ll n, m, k; cin >> n >> m >> k;
        // If total bits < 1 or trivial checks
        if(n + m == 0 || k < 1) {
            cout << -1 << "\n";
            continue;
        }
        // If difference bigger than k from the start
        if(abs(n - m) > k) {
            cout << -1 << "\n";
            continue;
        }
        // Decide which bit is +1 vs -1
        bool zeroPositive = (n >= m);
        ll zerosLeft = n, onesLeft = m;
        char zeroChar = '0', oneChar = '1';
        int plusVal = zeroPositive ? 1 : -1;  // value contributed by '0'
        int minusVal = zeroPositive ? -1 : 1; // value contributed by '1'

        // We'll build the string bit by bit with partial-sum
        // partial = 0 means #positive - #negative = 0
        int partial = 0;
        bool reachedK = false;
        string s;
        s.reserve(n + m);

        for(int i=0; i < n + m; i++){
            // Try to place '0' if we have zerosLeft
            bool canPlaceZero = (zerosLeft > 0) && (abs(partial + plusVal) <= k);
            bool canPlaceOne  = (onesLeft > 0)  && (abs(partial + minusVal) <= k);

            if(canPlaceZero){
                s.push_back(zeroChar);
                partial += plusVal;
                zerosLeft--;
            }
            else if(canPlaceOne){
                // Place '1' if '0' is impossible
                s.push_back(oneChar);
                partial += minusVal;
                onesLeft--;
            } 
            else {
                partial = 999999;
                break;
            }
            if(abs(partial) == k) reachedK = true;
        }

        if(zerosLeft == 0 && onesLeft == 0 && reachedK && abs(partial) <= k) {
            cout << s << "\n";
        } 
        else {
            cout << -1 << "\n";
        }
    }
}
/*
  -----     -----    -----    ----   
 |     -   |        |        |    |  
 |     -    -----    -----   |----   
 |     -   |        |        |       
  -----     -----    -----   |       
*/