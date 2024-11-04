// number of distinct charachters in user name = odd then male otherwise female
#include<bits/stdc++.h>

using namespace std;


int main(){
string s ;
cin >> s;

unordered_set<int> present;

for(char c: s){
        present.insert(c);
}

int count = present.size();

if(count & 1) cout << "IGNORE HIM!" << endl;
else cout << "CHAT WITH HER!" << endl;
}