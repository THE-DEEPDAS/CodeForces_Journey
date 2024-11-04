// there are n + 1 pylons numbered 0 to n where ith one has hi height
// player has to reach nth pylon with the only possible move i.e. jumping from kth pylon to (k + 1)th pylon
// for the jump player's energy increases by hk - hk+1 
// player must have a non-negative energy at any moment in time
// initially caisa has 0 energy and is on oth pylon 
// for each dollar we can increase the height of next pylon by 1
// find minimum dollars needed to spend to complete this game
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n;
    cin >> n;

    vector<ll> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    ll energy = 0, dollars = 0;
    dollars += heights[0];
    
    for(ll i = 0; i < n - 1; i++){
        energy += heights[i] - heights[i + 1];
        if(energy < 0){
            dollars += abs(energy);
            energy = 0;
        }
    }

    cout << dollars << endl;

}