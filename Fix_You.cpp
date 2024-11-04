// each point on the conveyer belt is (i,j)
// if it is written R means luggaje goes to (i, j + 1) and if Down is written then (i + 1,j)
// if we keep luggage at any point,luggage should reach (n,m) which is collection point
// we want to find minumum changes to fix the belt
typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcases = 0;
    cin >> testcases;

    for(int testcase = 0; testcase < testcases; testcase++){
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }

        /* int changes = 0;

        int position_x = 0 , position_y = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m - 1; j++){
                if(grid[i][j] == 'R'){
                    position_x ++;
                    if(position_x >= m){
                        changes ++;
                        grid[i][j] = 'D';
                        position_x --;
                        position_y ++; 
                    }
                }
                else if(grid[i][j] == 'D'){
                    position_y ++;
                    if(position_y >= n){
                        changes ++;
                        grid[i][j] = 'R';
                        position_y --;
                        position_x ++;
                    }
                }
            }
        }

        cout << changes << "\n"; */

        int changes = 0;
        // Count changes in the last row
        for (int j = 0; j < m; j++) {
            if (grid[n-1][j] == 'D') {
                changes++;
            }
        }

        // Count changes in the last column
        for (int i = 0; i < n; i++) {
            if (grid[i][m-1] == 'R') {
                changes++;
            }
        }

        cout << changes << endl;
    }
}