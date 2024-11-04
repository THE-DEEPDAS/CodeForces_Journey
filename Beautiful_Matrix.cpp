#include <bits/stdc++.h>

using namespace std;

int main()
{
    //this is how you declare a 5*5 matrix with all values = 0
    vector<vector<int>> matrix(5 ,vector<int>(5));

    //this is how you fill the matrix with user input
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int temp = 0;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }

    int row = 0, column = 0;
    // now beautiful check
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(matrix[i][j] == 1){
                row = i;
                column = j;
                break;
            }
        }
    }
    cout << abs(row - 2) + abs(column - 2) << endl;
}