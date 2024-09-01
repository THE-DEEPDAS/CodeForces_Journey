// we need to find that can sum of a ones and b twos be 0
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll a, b;
        cin >> a >> b;
        // if a is odd NO
        // else if a is even and b is odd then check if a >= 2, then yes else no
        // else if a and b both are even then yes
        if((a == 0 && b % 2 == 1) || (a % 2 == 1)){
            cout << "No" << endl;
        }
        else{
            if((a >= 2) && (b % 2 == 1)){
                cout << "Yes" << endl;
            }
            else if (a % 2 == 0 && b % 2 == 0){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
}