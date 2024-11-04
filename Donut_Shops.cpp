// shop1 -> a rupees/donut
// shop2 -> b donuts in c rupees
// in shop2 we need to but boxes only
// how many donuts to buy to get donuts cheaper at shop1
// how manu donuts to buy to get donuts cheaper at shop2
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testcases = 0;
    cin >> testcases;

    for (int testcase = 0; testcase < testcases; testcase++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        /*
        ll shop1_donuts = 1, shop2_donuts = b;

        if (c <= a)
        {
            cout << -1 << " ";
        }
        else
        {
            while (shop1_donuts * a > ceil(double(shop1_donuts) / b) * c)
            {
                shop1_donuts++;
            }
            cout << shop1_donuts << " ";
        }

        if (a * b == c)
        {
            cout << -1 << endl;
        }
        else
        {
            while (shop2_donuts * a < ceil(double(shop2_donuts) / b) * c)
            {
                shop2_donuts += b;
            }
            cout << shop2_donuts << endl;
        } 
        */

       // new approach to solve it 
        ll shop1_donuts = -1 , shop2_donuts = -1;
        if(a < c) shop1_donuts = 1;
        if(a * b > c) shop2_donuts = b;
        cout << shop1_donuts << " " << shop2_donuts << endl;
    }
}