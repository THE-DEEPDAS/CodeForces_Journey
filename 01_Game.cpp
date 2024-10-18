// in one move one can delete 01 or 10 from the array
// alice makes first move
// binary string is given and we need to find who will win
// game ends when no one can delete anything
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll testcases;
    cin >> testcases;

    for (ll testcase = 0; testcase < testcases; testcase++)
    {
        string binaryString;
        cin >> binaryString; 

        ll count = 0, consecutives = 1;
        char first = binaryString[0];
        for (ll i = 1; i < binaryString.length(); i++)
        {
            if (binaryString[i] == first)
            {
                consecutives++;
            }
            else if(consecutives > 0){
                count++;
                consecutives--;
            }
            else{
                first = binaryString[i];
                consecutives = 1;
            }
        }

        if (count % 2 == 0)
        {
            cout << "NET" << endl; 
        }
        else
        {
            cout << "DA" << endl; 
        }
    }
}