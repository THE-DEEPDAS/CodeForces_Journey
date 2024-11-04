// we call appartment boring if it has same numbers like 11,222,1111
// there are 1 to 10000 buildings
// count keypress

#include <bits/stdc++.h>

using namespace std;

int digits_count(int n){
    if (n == 1) return 1;
    else if (n == 2) return 3;
    else if (n == 3) return 6;
    else if (n == 4) return 10;
}

int main()
{
    int testcases = 0;
    cin >> testcases;

    for(int i = 0; i < testcases; i++){
        int answerer = 0;
        cin >> answerer;

        int consits_of = 0;
        int digits = 0;
        while(answerer > 0){
            consits_of = answerer % 10;
            digits++;
            answerer /= 10;
        }

        // in each time he has 1 + 11 + 111 + 1111 = 10 presses
        int answer = 0;
        answer = (consits_of - 1) * 10 + digits_count(digits);
        cout << answer << endl;
    }
}