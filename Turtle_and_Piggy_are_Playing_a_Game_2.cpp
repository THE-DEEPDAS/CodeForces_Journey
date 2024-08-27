// in a game turtle always takes first turn and then on alternate turns
// we have n lengthed integer sequence, if current length = 1 then end the game
// on turtle's turn set ai to max(ai, ai+1) and remove ai+1
// on piggy's turn set ai to min(ai, ai+1) and remove ai+1
// find the value left at end
// so turtle wants to maximise the value of a1 and piggy wants to minimise the value of a1
// so we have to find how many turns each will get 
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }

        ll turtle_turns = 0;
        if(n % 2 != 0){
            turtle_turns = (n - 1) / 2;
        }
        else{
            turtle_turns = n / 2;
        }
        ll piggy_turns = n - turtle_turns - 1;

        // now on each turtle's turn we remove min value from current array 
        // and on each piggy's turn we remove max value from current array
        sort(a.begin(), a.end());
        // remove the last piggy_turns elements
        a.resize(n - piggy_turns);
        // remove the first turtle_turns elements
        a.erase(a.begin(), a.begin() + turtle_turns);

        cout << a[0] << endl;
    }
}