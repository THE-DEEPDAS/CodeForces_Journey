// n stops of tram and at station i , ai people leave and bi enters
//find minimum capacity to fit all
#include<bits/stdc++.h>

using namespace std;


int main(){
int stops = 0;
cin >> stops;

int people_in_tram = 0,max_people = INT_MIN;
while(stops --){
    int a, b;
    cin >> a >> b;
    people_in_tram += b - a;
    max_people = max(max_people, people_in_tram);
}
cout << max_people << endl;
}