// we want n pipes and n people but we hvae 1 pipe and some pipes_available
// pipes_available are with the output 2, 3, 4 upto k
// find minimum pipes_available to achieve n outputs , if not possible then print -1
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

bool possible(ll pipes_available, ll n, ll k){
    ll pipes = 1; 

    while (pipes_available > 0 && pipes < n) {
        ll newPipes = min(n - pipes, pipes * (k - 1)); // max additional pipes we can create
        pipes += newPipes;
        pipes_available--;
    }
    return pipes >= n;
}

int main(){
    ll n, k;
    cin >> n >> k;

    if(n <= k){
        cout << 1 << endl;
        return 0;
    }

    ll low = 0, high = n - 1, result = -1;
    while(low < high){
        ll mid = low + (high - low) / 2;
        // check if we can make it with mid number of pipes
        if(possible(mid, n, k)){
            result = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    if(result)
    cout <<  << endl;
}