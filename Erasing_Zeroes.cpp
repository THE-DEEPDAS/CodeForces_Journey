// we need a string which has continuous ones
// to make it a one we can eliminate zeroes
// return how many zeroes to be deleted
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcases = 0;
    cin >> testcases;

    for(int i = 0; i < testcases; i++){
        string s;
        cin >> s;

        bool first_one = true;
        int first_one_index = 0 , last_one = 0;
        int index = 0;
        for(char c : s){
            if(c == '1'){
                if(first_one){
                    first_one_index = index;
                    first_one = false;
                }
                else{
                    last_one = index;
                }
            }
            index ++;
        }

        int answer = 0;

        for(int i = first_one_index; i < last_one ; i++){
            if(s[i] == '0'){
                answer++;
            }
        }

        cout << answer << endl;
    }
}