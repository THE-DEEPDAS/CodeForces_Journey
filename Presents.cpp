// n friends
// i gave a gift to Pi

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int friends = 0;
    cin >> friends;
    vector<int> gifts(friends);
    int i = 0;
    while (friends--)
    {
        cin >> gifts[i];
        i++;
    }
    vector<int> answer(i);
    for (int j = 0; j < i; j++)
    {
        answer[gifts[j] - 1] = j + 1;
    }
    for (int j = 0; j < i; j++)
    {
        cout << answer[j] << " ";
    }
}