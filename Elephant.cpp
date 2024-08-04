// elephant's house is at position 0
// in one step it can move 1,2,3,4 or 5 positions ahead
// x is where he needs to reach
// task : find min number of steps to get to his friend's house
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
ll x;
cin >> x;

cout << (x / 5) + (x % 5 == 0 ? 0 : 1) << endl;
}