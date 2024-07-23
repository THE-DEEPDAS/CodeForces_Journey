// bbok has n pages
// he reads the book with full efficiency on free days but doesn't read on busy days
// given that he will read how many pages o each day ,find the day on which he will complete the book
// Day 1 is Monday

typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ll n;
    cin >> n;

    // given that pages <= 1000 on each day
    vector<int> pages(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> pages[i];
    }

    ll days = 0;

    while (n > 0)
    {
        n -= pages[days % 7];
        days++;
    }

    if(days % 7 == 0) cout << 7 << endl;
    // As we don't want total days but just day of week
    else cout << days % 7 << endl;
}