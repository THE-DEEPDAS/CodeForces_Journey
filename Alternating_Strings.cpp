// length = even and numbers on even positions = same , odd positions = same
// we can choose an index and delete it from array, only 1 time
// replace s[i] with another letter
// min operations to make string alternating
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases = 0;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll n;
        cin >> n;

        string s;
        cin >> s;

        unordered_map<char , ll> even_chars;
        unordered_map<char , ll> odd_chars;
        unordered_map<char, ll> freq;

        if(n == 1){
            cout << 1 << endl;
            continue;
        }

        for (ll i = 0; i < n; i++)
        {
            freq[s[i]]++;
        }

        ll operations = 0;
        ll mini = INT_MAX;
        char min_occur;
        if(n % 2 == 1){
            operations++;
            for(auto& pair : freq){
                if(pair.second < mini){
                    mini = pair.second;
                    min_occur = pair.first;
                }
            }
            n--;
        }
        // now redefine the even and odd chars
        bool removed = false;
        for (ll i = 0; i < n + 1; i++){
            if(s[i] == min_occur){
                removed = true;
            }
            if((!removed && i % 2 == 0) || (removed && i % 2 == 1)){
                even_chars[s[i]]++;
            }
            else if((!removed && i % 2 == 1) || (removed && i % 2 == 0)){
                odd_chars[s[i]]++;
            }
        }

            // now all are of even length
            ll max_freq_even = INT_MIN, max_freq_odd = INT_MIN;
        for(auto& pair : even_chars){
            if(pair.second > max_freq_even){
                max_freq_even = pair.second;
            }
        }
        for(auto& pair : odd_chars){
            if(pair.second > max_freq_odd){
                max_freq_odd = pair.second;
            }
        }
        if(max_freq_even < n / 2){
            operations += n / 2 - max_freq_even;
        }
        if(max_freq_odd < n / 2){
            operations += n / 2 - max_freq_odd;
        }

        cout << operations << endl;
    }
}