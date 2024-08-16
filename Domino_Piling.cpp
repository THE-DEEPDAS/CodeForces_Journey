// M * N rectangle , we have domino of size 2 * 1 and we can rotate it
// each domino should cover 2 boxes 
// find max number of dominos that can be placed
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll m , n;
    cin >> m >> n;

    if(m * n < 2){
        cout << 0 << endl;
    }
    else if(m % 2 == 0 || n % 2 == 0){
        cout << m * n / 2 << endl;
    }
    else{
        cout << (m * n - 1) / 2  << endl;
    }
}