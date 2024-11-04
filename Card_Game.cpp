// in a card game , card's have number 1 to 10
// it has only 2 turns for each player
// if card of player 1 > card of player 2, player 1 wins
// player with max round wins , wins the game
// we want to find in how many cases player 1 can win
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        ll win_count = 0;

        if((a1 >= b1 && a2 > b2) || (a1 > b1 && a2 >= b2)){
            win_count += 2;
        }
        if((a1 >= b2 && a2 > b1) || (a1 > b2 && a2 >= b1)){
            win_count += 2;
        }

        cout << win_count << endl;  
    }
}