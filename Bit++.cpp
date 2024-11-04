#include<bits/stdc++.h>

using namespace std;


int main(){
    int testcases = 0;
    cin >> testcases;

    int x = 0;
    for(int i = 0; i < testcases; i++){
        string s;
        cin >> s;
        if(s == "X++"){x++;}
        else if(s == "++X"){++x;}
        else if(s == "X--"){x--;}
        else{--x;}
    }
    cout << x;
}