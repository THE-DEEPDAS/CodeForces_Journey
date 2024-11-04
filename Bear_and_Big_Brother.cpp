// weight of limak = a, weight of bob = b where a <= b
// after a year a -> 3a and b -> 2b , after how many year weight of limak > weight of bob
#include<bits/stdc++.h>

using namespace std;


int main(){
int a = 0 , b = 0;
cin >> a >> b ;

int years = 0;

while (a <= b){
    a = 3*a;
    b = 2*b;
    years++;
}
cout << years << endl;
}