//capitalise means first letter should be capital
#include<bits/stdc++.h>

using namespace std;

char to_upper(char c){
    if(c >= 'a' && c <= 'z')
        return c - 32;
    else
        return c;
}
int main(){
string word;
cin >> word;

word[0] = to_upper(word[0]);
cout << word << endl;
}