#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check_distinct(ll year){
        ll digits[4];
        for (ll i = 0; i < 4; i++){
            digits[i] = year % 10;
            year /= 10;
        }
        sort(digits, digits + 4);
        if(digits[0] != digits[1]  && digits[1] != digits[2] && digits[2] != digits[3] && digits[3] != digits[0]){
            return true;
        }
        return false;
    }

int main() {
    // string year_string;
    // cin >> year_string;

    // ll millenium = year_string[0] - '0';
    // ll century = year_string[1] - '0';
    // ll decade = year_string[2] - '0';
    // ll year = year_string[3] - '0';

    // if (((year + 1) != 10) && (year + 1) != millenium && (year + 1) != century && (year + 1) != decade) {
    //     year = year + 1;
    // } 
    // else if (((decade + 1) != 10) && (decade + 1) != millenium && (decade + 1) != century && (decade + 1) != year) {
    //     decade = decade + 1;
    // } 
    // else if (((century + 1) != 10) && (century + 1) != millenium && (century + 1) != decade && (century + 1) != year) {
    //     century = century + 1;
    // } 
    // else if (((millenium + 1) != 10) && (millenium + 1) != decade && (millenium + 1) != year && (millenium + 1) != century) {
    //     millenium = millenium + 1;
    // } 
    // else if (year + 1 == 10) {
    //     year = 0;
    //     decade += 1;
    //     if (year == decade || year == century || year == millenium || decade == century || decade == millenium) {
    //         year = 9;
    //         decade -= 1;
    //     }
    // } 
    // else if (decade + 1 == 10) {
    //     decade = 0;
    //     century += 1;
    //     if (decade == century || decade == millenium || century == millenium || century == year) {
    //         decade = 9;
    //         century -= 1;
    //     }
    // } 
    // else if (century + 1 == 10) {
    //     century = 0;
    //     millenium += 1;
    //     if (century == millenium || century == year || century == decade || millenium == decade || millenium == year) {
    //         century = 9;
    //         millenium -= 1;
    //     }
    // }

    // cout << millenium << century << decade << year << endl;

    ll year;
    cin >> year;

    ll next_year = 0;
    while(year <= 9012){
        year++;
        if(check_distinct(year)){
            next_year = year;
            break;
        }
    }
    cout << next_year << endl;
}
