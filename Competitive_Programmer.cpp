// he asked n grandmasters for their hardwork
// the number of hours they spent doing problems are in an array
// but bob wrote number of minutes i.e. 60 * xi , also he can write with leading zeroes
// alice rearranged the digits or replaced with a random number in array y
// for each number yi can the number be permutation of any number divisible by 60
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll n;
    cin >> n;

    vector<string> hours(n);
    for(ll i = 0; i < n; i++){
        cin >> hours[i];
    }

    // print cyan if not possible and red if possible
    // so we need to check the divisiblity rule by 10 and 6

    
    for(string s : hours){
        // these are divisiblity check variables
        bool three = false;
        bool two = false;
        bool ten = false;
        ll sum = 0;
        for(char c : s){
            if(!ten && c == '0'){
                ten = true;
            }
            else if((c - '0') % 2 == 0){
                two = true;
            }
            sum += c - '0';
        }
        if(sum % 3 == 0){
            three = true;
        }

        if(three && ten && two){
            cout << "red" << endl;
        }
        else{
            cout << "cyan" << endl;
        }
    }
}