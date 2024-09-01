// robot is placed at origin and it can do 4 type of operations[i]
// U means up , D means down , L means left and R means right
// we have sequence of n operations[i] and we want to make it such that we reach (x , y) at the end
// we want min value of max_index_changed - min_index_changed + 1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool can(int x, int y, int n) {
  x = abs(x);
  y = abs(y);
  return (x + y) % 2 == n % 2 && x + y <= n;
}

int main()
{
    ll n;
    cin >> n;

    string operations;
    cin >> operations;

    ll x, y;
    cin >> x >> y;

    // first find where it reaches with these operations[i]
    ll final_x = 0, final_y = 0;
    for (char c : operations)
    {
        if (c == 'D')
        {
            final_y--;
        }
        else if (c == 'U')
        {
            final_y++;
        }
        else if (c == 'L')
        {
            final_x--;
        }
        else
        {
            final_x++;
        }
    }

    ll diff_x = (final_x - x);
    ll diff_y = (final_y - y);

    if (abs(diff_x) % 2 == 1 || abs(diff_y) % 2 == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    
    // else
    // {
    //     if(diff_x != 0){
    //         ll to_be_changed_x = diff_x / 2;
    //         if(to_be_changed_x > 0){
    //             // means R change to L
    //         }
    //         else{
    //             // L change to R
    //         }
    //     }
    //     if(diff_y != 0){
    //         ll to_be_changed_y = diff_y / 2;
    //         if(to_be_changed_y > 0){
    //             // means U changes to D
    //         }
    //         else{
    //             // D changes to U
    //         }
    //     }
    // }

    int right = n, left = -1;
    while (right - left > 1)
    {
        int mid = (left + right) / 2;
        int leftX = 0, leftY = 0, rightX = 0, rightY = 0;

        // Calculate the initial counts of directions from mid to end
        for (int i = mid; i < n; i++)
        {
            if (operations[i] == 'U')
                rightY++;
            if (operations[i] == 'D')
                rightY--;
            if (operations[i] == 'L')
                rightX--;
            if (operations[i] == 'R')
                rightX++;
        }

        bool found = false;
        for (int i = 0; i + mid <= n; i++)
        {
            found |= can(x - leftX - rightX, y - leftY - rightY, mid);

            if (operations[i] == 'U')
                leftY++;
            if (operations[i] == 'D')
                leftY--;
            if (operations[i] == 'L')
                leftX--;
            if (operations[i] == 'R')
                leftX++;

            if (i + mid < n)
            {
                if (operations[i + mid] == 'U')
                    leftY--;
                if (operations[i + mid] == 'D')
                    leftY++;
                if (operations[i + mid] == 'L')
                    leftX++;
                if (operations[i + mid] == 'R')
                    leftX--;
            }
        }

        found ? right = mid : left = mid;
    }
    cout << right << endl;
}