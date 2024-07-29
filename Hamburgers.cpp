// we need only 3 elements BSC to make a hamburger and recipie is the order of string of these 3 letters
// BSCBC means bread is lowermost and Cheese is the topmost
// he has nb, ns, nc quantities of each respectively and prices are pb ,ps ,pc
// he has total r roubles
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class HamburgerMaker {
public:
    HamburgerMaker(string recipe, ll nb, ll ns, ll nc, ll pb, ll ps, ll pc, ll roubles) 
        : recipe(recipe), nb(nb), ns(ns), nc(nc), pb(pb), ps(ps), pc(pc), roubles(roubles) {
        calculateRequirements();
    }

    bool can_make(ll x) {
        ll need_b = max(0LL, required_b * x - nb);
        ll need_s = max(0LL, required_s * x - ns);
        ll need_p = max(0LL, required_p * x - nc);
        
        ll cost = need_b * pb + need_s * ps + need_p * pc;
        return cost <= roubles;
    }

private:
    string recipe;
    ll nb, ns, nc;
    ll pb, ps, pc;
    ll roubles;

    ll required_b = 0, required_s = 0, required_p = 0;

    void calculateRequirements() {
        for (char c : recipe) {
            if (c == 'B') required_b++;
            else if (c == 'S') required_s++;
            else if (c == 'C') required_p++;
        }
    }
};

int main() {
    string recipe;
    cin >> recipe;
    
    ll nb, ns, nc;
    cin >> nb >> ns >> nc;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll roubles;
    cin >> roubles;

    HamburgerMaker maker(recipe, nb, ns, nc, pb, ps, pc, roubles);

    // Binary search to find the maximum number of hamburgers
    ll low = 0, high = 1e13; // High value is large enough to cover possible answers
    while (low < high) {
        ll mid = low + (high - low) / 2;
        if (maker.can_make(mid)) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    // low is the first value that cannot be achieved, so subtract 1
    cout << low - 1 << endl;
}
