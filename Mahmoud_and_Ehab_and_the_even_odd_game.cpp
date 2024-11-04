// Ehab chooses a number n and then they take turn starting from Mahmoud
// in each turn they subtract a number a from n
// for mahmoud , a has to be even and for ehab , a has to be odd
// if one is not able to find out such a number then he looses
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n;
    cin >> n;

    if(n % 2 == 0){
        cout << "Mahmoud" << endl;
    }
    else{
        cout << "Ehab" << endl;
    }
}