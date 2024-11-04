// n candies all of different tastiness and 1 based indexing
// largest XOR sum of k candies
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

ll XOR(ll n){
    if(n % 4 == 0){
        return n;
    }
    else if(n % 4 == 1){
        return 1;
    }
    else if(n % 4 == 2){
        return (n + 1);
    }
    else{
        return 0;
    }
}

int main()
{
     string s;
    getline(cin, s);  // Get the entire line of input

    ll n = 0, k = 0;
    istringstream iss(s);
    iss >> n >> k;  // Extract the two integers from the string

    if(n == k){
        cout << XOR(n) << endl;
    }
    else{
        ll skipables = n - k;
        ll rotations = n / 4;
        ll skip_3s = 0, skip_1s = 0, skip_0s = 0, skip_2s = 0;
        if(skipables >= rotations){
            skipables -= rotations;
            skip_3s = rotations;
        }
        else{
            skip_3s = skipables;
            skipables = 0;
        }

        if(skipables >= rotations){
            skipables -= rotations;
            skip_1s = rotations;
        }
        else{
            skip_1s = skipables;
            skipables = 0;
        }

        if(skipables >= rotations){
            skipables -= rotations;
            skip_0s = rotations;
        }
        else{
            skip_0s = skipables;
            skipables = 0;
        }

        if(skipables >= rotations){
            skipables -= rotations;
            skip_2s = rotations;
        }
        else{
            skip_2s = skipables;
            skipables = 0;
        }

        ll max_xor_sum = 0;
        for(ll i = 1; i <= n; i++){
            ll which_to_skip = i % 4;
            switch (which_to_skip)
            {
            case 0:
                if(skip_0s > 0){
                    skip_0s--;
                }
                else{
                    max_xor_sum = (max_xor_sum ^ i);
                }
                break;
            
            case 1:
                if(skip_1s > 0){
                    skip_1s--;
                }
                else{
                    max_xor_sum = (max_xor_sum ^ i);
                }
                break;

            case 2:
                if(skip_2s > 0){
                    skip_2s--;
                }
                else{
                    max_xor_sum = (max_xor_sum ^ i);
                }
                break;
            
            case 3:
                if(skip_3s > 0){
                    skip_3s--;
                }
                else{
                    max_xor_sum = (max_xor_sum ^ i);
                }
                break;
            
            default:
                break;
            }
        }

        cout << max_xor_sum << endl;
    }
}
/*
1022 10
Output
35
Answer
1023
Checker Log
wrong answer 1st numbers differ - expected: '1023', found: '35'
*/