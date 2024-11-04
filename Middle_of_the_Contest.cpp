// contest starts at h1:m1 and ends at h2:m2 
// we have to find the middle of the competition
// minutes are always even and it is a 24hr clock
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    int h1, m1, h2, m2;
    char isto;
    cin >> h1 >> isto >> m1 >> h2 >> isto >> m2;

    // convert hours to minutes
    int h1_in_minutes = h1 * 60;
    int h2_in_minutes = h2 * 60;

    // find middle minutes
    int middle_minutes = (h1_in_minutes + m1 + h2_in_minutes + m2) / 2;

    // convert back to hours and minutes
    string hours = to_string(middle_minutes / 60);
    string minutes = to_string(middle_minutes % 60);
    
    if(hours.length() == 1){
        hours = "0" + hours;
    }
    if(minutes.length() == 1){
        minutes = "0" + minutes;
    }
    
    // print the result
    cout << hours << ":" << minutes << endl;
}