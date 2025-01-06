#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Segment tree node
struct Node {
    ll minVal = LLONG_MAX;
    ll maxVal = LLONG_MIN;
    
    void merge(const Node& left, const Node& right) {
        minVal = min(left.minVal, right.minVal);
        maxVal = max(left.maxVal, right.maxVal);
    }
};

class SegmentTree {
    vector<Node> tree;
    int n;
    
    void build(int node, int start, int end, vector<ll>& arr) {
        if(start == end) {
            tree[node].minVal = tree[node].maxVal = arr[start];
            return;
        }
        
        int mid = (start + end) / 2;
        build(2*node+1, start, mid, arr);
        build(2*node+2, mid+1, end, arr);
        tree[node].merge(tree[2*node+1], tree[2*node+2]);
    }
    
    Node query(int node, int start, int end, int l, int r) {
        if(r < start || l > end) {
            return Node();
        }
        
        if(l <= start && end <= r) {
            return tree[node];
        }
        
        int mid = (start + end) / 2;
        Node left = query(2*node+1, start, mid, l, r);
        Node right = query(2*node+2, mid+1, end, l, r);
        
        Node result;
        result.merge(left, right);
        return result;
    }
    
    void update(int node, int start, int end, int idx, ll val) {
        if(start == end) {
            tree[node].minVal = tree[node].maxVal = val;
            return;
        }
        
        int mid = (start + end) / 2;
        if(idx <= mid)
            update(2*node+1, start, mid, idx, val);
        else
            update(2*node+2, mid+1, end, idx, val);
            
        tree[node].merge(tree[2*node+1], tree[2*node+2]);
    }
    
public:
    SegmentTree(vector<ll>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(0, 0, n-1, arr);
    }
    
    Node query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }
    
    void update(int idx, ll val) {
        update(0, 0, n-1, idx, val);
    }
};

ll findMaxConvenience(SegmentTree& st, int n) {
    ll maxConvenience = 0;
    
    // Try all possible segments
    for(int len = 1; len <= min(3, n); len++) {
        for(int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            Node range = st.query(l, r);
            ll convenience = range.maxVal - range.minVal - (r - l);
            maxConvenience = max(maxConvenience, convenience);
        }
    }
    
    return maxConvenience;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, q;
        cin >> n >> q;
        
        vector<ll> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // Build segment tree
        SegmentTree st(arr);
        cout << findMaxConvenience(st, n) << '\n';
        
        // Process queries
        while(q--) {
            int p;
            ll x;
            cin >> p >> x;
            p--;
            st.update(p, x);
            cout << findMaxConvenience(st, n) << '\n';
        }
    }
    return 0;
}