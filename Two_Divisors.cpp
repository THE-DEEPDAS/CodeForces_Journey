// we have to find the 2 biggest divisors of a number n leaving itself
// so we have the 2 largest divisors then find number n
// we have a sequence a, whose product was 2023
// k numbers are removed and we now have a sequence B on length n
// from b find a and the elements removed from it
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to calculate GCD using the Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++){
        ll a, b;
        cin >> a >> b;

        if(b % a == 0){
            cout << b * (b / a) << endl;
        }
        else{
            cout << (a * b) / gcd(a, b) << endl;
        }
    }
}