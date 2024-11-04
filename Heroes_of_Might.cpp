// we have rust dragon and opponent has group of peasants, find minimum health of our rust 
// dragon to win the game. rust dragon has an initial health of hd and deals d damage in 1 hit
// there are n groups of peasants and ith group has a[i] peasants with health of hp
// we choose a group and attack it if health <= 0 , then peasants group is eliminated
// each group of peasants that is still alive attacks the dragon, each inflicts 1 damage
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canDragonWin(ll n, ll d, ll hp, vector<ll>& a, ll hd) {
    vector<ll> health(n);
    for (ll i = 0; i < n; i++) {
        health[i] = a[i] * hp;  // initial health for each group of peasants
    }

    while (true) {
        // find the group with the maximum current health to attack
        ll max_index = -1;
        ll max_health = -1;
        for (ll i = 0; i < n; i++) {
            if (health[i] > 0 && health[i] > max_health) {
                max_health = health[i];
                max_index = i;
            }
        }

        if (max_index == -1) {
            // all groups are destroyed, dragon wins
            return true;
        }

        // Dragon attacks the group with the highest remaining health
        health[max_index] -= d;

        // Calculate total damage done by peasants
        ll total_damage = 0;
        for (ll i = 0; i < n; i++) {
            if (health[i] > 0) {
                ll peasants_alive = (health[i] + hp - 1) / hp;  // equivalent to ceil(health[i] / hp)
                total_damage += peasants_alive;
            }
        }

        // Dragon takes damage from all remaining peasants
        hd -= total_damage;
        if (hd <= 0) {
            // Dragon's health drops to zero or below
            return false;
        }
    }
}

int main() {
    ll testcases;
    cin >> testcases;

    while (testcases--) {
        ll n, d, hp;
        cin >> n >> d >> hp;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll left = 1, right = 1e18, result = right;

        // Binary search to find the minimum initial health required for the dragon to win
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            if (canDragonWin(n, d, hp, a, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << result << endl;
    }
}