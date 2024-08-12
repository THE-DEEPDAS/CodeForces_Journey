#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll s = 0;
    cin >> s;

    bool found = false;
    string str = to_string(s);
    ll count = str.size();

    for(ll i = 1; i < count; i++){
        if(str[i] == '1'){
            found = true;
            break;
        }
    }

    if(found){
        cout << (count / 2) + 1<< endl;
    }
    else{
        cout << count / 2 << endl;
    }
}