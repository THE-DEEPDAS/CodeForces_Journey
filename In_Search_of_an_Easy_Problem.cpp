// asks n people and 0 means easy and 1 means hard
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int people = 0;
    cin >> people;
    bool check = true; // to see if we get hard
    while (people--)
    {
        int opinion = 0;
        cin >> opinion;

        if (opinion == 1)
        {
            cout << "HaRd" << endl;
            check = false;
            break;
        }
    }
    if (check)
    {
        cout << "EasY" << endl; // if we didn't get hard, then all are easy.
    }
}