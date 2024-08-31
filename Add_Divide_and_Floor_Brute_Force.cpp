// we want to make all the elements of array equal
// we can choose a number x and then we replace all elements with floor(a[i] + x / 2)
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }

        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        ll max_diff = INT_MIN, num1 , num2;
        for(ll i = 0; i < n - 1; i++){
            if(abs(a[i + 1] - a[i]) > max_diff){
                max_diff = abs(a[i + 1] - a[i]);
                num1 = a[i];
                num2 = a[i + 1];
            }
        }
        // so each time difference becomes (difference + 1) / 2 but if bigger number is odd
        // then difference becomes difference / 2
        vector<ll> print;
        ll count1 = 0;
        ll count = 0;
        while(max_diff != 1){
            if(num1 > num2){
                swap(num1, num2);
            }
            // so num 2 will be the greater one always
            if(num2 % 2 != 1){
                if(count1 < n){
                    print.push_back(2);
                    count1++;
                }
                num1 = (num1 + 2) / 2;
                num2 = (num2 + 2) / 2;
            }
            else{
                if(count1 < n){
                    print.push_back(3);
                    count1++;
                }
                num1 = (num1 + 3) / 2;
                num2 = (num2 + 3) / 2;
            }
            max_diff = (max_diff) / 2;
            count++;
        }
        
        if(count + 1 <= n){
            cout << count + 1 << endl;
            for (ll i = 0; i < count; i++){
                cout << print[i] << " ";
            }
            if(num1 % 2 != 0 || num2 % 2 != 0){
                cout << 3 << endl;
            }
        }
        else{
            cout << count + 1 << endl;
        }
    }
}