//numbers containig only 4 and 7 are considered to be lucky
// if there are lucky number of lucky numbers then it is nearly lucky
#include<bits/stdc++.h>

using namespace std;


int main(){
 long long number = 0;
 cin >>number;

 int count = 0;
 while( number > 0 && count<=7){
     int digit = number % 10;
     if(digit == 4 || digit == 7) count++;
     number /= 10;
 }
 if(count == 4 || count == 7) cout << "YES" << endl;
 else cout << "NO" << endl;
}