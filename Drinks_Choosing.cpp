// n students have favourite drink in range 1 to k and each's favourite drink is denoted by ai
// there are infinite sets and each sets has 2 potions of drinks
// so minimum number of sets to give all 1 drink = ceil(n / 2) 
// find maximum number of students who will have favourite drinks
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n , k;
    cin >> n >> k;

    ll favourite;
    vector<ll> favourite_count(k);
    for(ll i = 0; i < n; i++){
        cin >> favourite;
        favourite_count[favourite - 1]++;
    }

    ll number_of_sets = 0;
    if(n & 1 == 0){
        number_of_sets = n / 2;
    }
    else{
        number_of_sets = (n + 1) / 2;
    }

    sort(favourite_count.begin(),favourite_count.end());
    ll ans = 0;
    for(ll i = k - 1; i >= 0; i--){

        ll sets_required = 0;
        if(favourite_count[i] & 1){
            sets_required = favourite_count[i] / 2 + 1;
        }
        else{
            sets_required = favourite_count[i] / 2;
        }

        if(number_of_sets - sets_required >= 0){
            ans += favourite_count[i];
            number_of_sets -= sets_required;
        }
        else{
            ans += number_of_sets * 2;
            break;
        }
    }

    cout << ans << endl;
}