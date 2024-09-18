// find the number which differs in evenness
// means if all numbers are even but 1 is odd then that one is differing
// if all are odd but 1 is even then that one is difffering
// output the index of that number
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    vector<ll> a(n);
    unordered_map<ll, ll> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] & 1)
            mpp[1]++;
        else mpp[0]++;
    }

    ll idx = 0;
    if(mpp[0] == 1){
        while(a[idx] & 1){
            idx++;
        }
        cout << idx + 1;
    }
    else{
        while(!(a[idx] & 1)){
            idx++;
        }
        cout << idx + 1;
    }
    // ll first = a[0];
    // ll second = a[1];
    // ll third = a[2];

    // if(first == second == third){
    //     // first is odd so differing will be even
    //     if(first & 1){

    //     }
    // }
}