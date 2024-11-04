// shovel price = k burles
// we have unlimited 10 burles coins but only one 'r' burles coin
// we should be able to buy without any change and minimum shovels to be bought
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll k , r;
    cin >> k >> r;

    ll count = 1;
    while(((count * k) % 10 != 0) && (((count * k) - r) % 10 != 0)){
        count ++;
    }
    cout << count << endl;
}
