// there are n emotes ,  ith emote increases happiness of opponent by ai 
// we can use emotes m times, we can not use a same emote more than k times in a row
// find max happiness of opponent
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n , m , k;
    cin >> n >> m >> k;

    vector<ll> happiness(n);
    for(ll i = 0; i < n; i++){
        cin >> happiness[i];
    }

    sort(happiness.rbegin(),happiness.rend());
    
    ll maximum_happiness = 0;

    // naive / brute force approach
    // bool changed = true;
    // ll idx = 0;
    // while(m > k){
    //     if(changed){
    //         maximum_happiness += k * happiness[idx++];
    //         m -= k;
    //         changed = false;
    //     }
    //     else{
    //         maximum_happiness += happiness[idx--];
    //         m--;
    //         changed = true;
    //     }
    // }
    // maximum_happiness += m * happiness[idx];

    // if m = 25 , k = 8 then 8 + 1 + 8 + 1 + 7
    // so add max happiness and 2nd best happiness 25 / 9 times
    // then remaining times add max happiness
    // Use the most happy emote `k` times, then use the second most happy emote once
    ll full_patterns = m / (k + 1);  // Number of full patterns we can use
    ll remaining_uses = m % (k + 1); // Remaining uses after full patterns

    // Happiness from full patterns
    maximum_happiness += full_patterns * (k * happiness[0] + happiness[1]);

    // Happiness from remaining uses
    maximum_happiness += remaining_uses * happiness[0];

    cout << maximum_happiness << endl;
}