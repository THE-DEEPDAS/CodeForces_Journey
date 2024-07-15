// n soldiers
// SuperDuper thinks order is corect if least height is first and maximum height is second last
// we need to bring max heighted above and least heighted at last
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int soldiers = 0;
    cin >> soldiers;

    vector<int> heights(soldiers);
    int max_height = INT_MIN, min_height = INT_MAX;
    int max_index = -1, min_index = -1;
    for (int i = 0; i < soldiers; i++)
    {
        cin >> heights[i];
        if (heights[i] > max_height)
        {
            max_height = heights[i];
            max_index = i;
        }
        if (heights[i] <= min_height)
        {
            min_height = heights[i];
            min_index = i;
        }
    }
    //If the maximum height soldier is before the minimum height soldier in the original list,we need to reduce one move because after moving the max soldier to the front, the min soldier's position is shifted one place left
    int set_ahead = max_index;
    int set_behind = soldiers - 1 - min_index;

    if (max_index > min_index)
    {
        cout << set_ahead + set_behind - 1 << endl;
    }
    else
    {
        cout << set_ahead + set_behind << endl;
    }
}