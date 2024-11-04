// 1 to n numbers are written on white board
// now we want to delete 2 numbers a and b and replace it with (a+b)/2
// print the least possible number after n-1 operations and then all the number pairs
// we have replaced
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long testcases = 0;
    cin >> testcases;

    for (int testcase = 0; testcase < testcases; testcase++)
    {
        ll n;
        cin >> n;

        priority_queue<ll> pq;
        // we push all elements starting from larger ones in a priority queue
        for(ll i = n; i >= 1; i--){
            pq.push(i);
        }

        ll a , b , c;
        cout << 2 << endl;
        while(pq.size() > 1){
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            cout << a << " " << b << endl;
            c = a + b;
            if(c & 1){
                c++;
            }
            c /= 2;
            pq.push(c);
        }
    }
}