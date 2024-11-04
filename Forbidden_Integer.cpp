// we want to make an integer n from the integer 1 to k(unlimited quantity) but we have a missing integer x
// can we make an integer n
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for (int testcase = 0; testcase < testcases; testcase++){
        ll n , k , x;
        cin >> n >> k >> x;
        if(x != 1){
            cout << "Yes" << endl;
            cout << n << endl;
            while(n--){
                cout << 1 << " ";
            }
            cout << endl;
        }
        else{
            // if 1 is blocked
            if(k >= 3){
                cout << "Yes" << endl;
                ll count = n / 2;
                ll remainder = n % 2;
                if(remainder == 1){
                    // so we will need one 3 to compensate.
                    count--;
                }
                if(remainder){
                    cout << count + 1 << endl;
                }
                else{
                    cout << count << endl;
                }
                while(count--){
                    cout << 2 << " ";
                }
                if(remainder == 1){
                    cout << 3;
                }
                cout << endl;
            }
            else if(k == 2){
                if(n % 2 == 0){
                    ll count = n / 2;
                    cout << "Yes" << endl;
                    cout << count << endl;
                    while(count--){
                        cout << 2 << " ";
                    }
                    cout << endl;
                }
                else{
                    cout << "No" << endl;
                }
            }
            else{
                cout << "No" << endl;
            }
        }
    }
}