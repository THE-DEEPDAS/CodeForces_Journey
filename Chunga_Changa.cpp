// currency of the new island chunga-changa is chizik
// z chizhiks per coconut and shaha have x chiziks and masha have y chiziks
// they can exchange chiziks to buy maximum coconuts but minimise the number of chiziks to be given
typedef long long ll;
#include<bits/stdc++.h>

using namespace std;

int main(){
    ll x , y , z;
    cin >> x >> y >> z;

    ll remainder_from_shaha, remainder_from_masha;
    remainder_from_shaha = x % z;
    remainder_from_masha = y % z;

    ll max_coconuts = (x + y) / z;
    ll shahas_coconuts = x / z;
    ll mashas_coconuts = y / z;
    ll coconuts_added = max_coconuts - shahas_coconuts - mashas_coconuts;
    if(coconuts_added == 0){
        cout << max_coconuts << " " << 0 << endl;
    }
    else{
        ll remaining_price = coconuts_added * z;
        // ll min_remainder = min(remainder_from_shaha, remainder_from_masha);
        ll max_remainder = max(remainder_from_shaha, remainder_from_masha);
        cout << max_coconuts << " " << remaining_price - max_remainder << endl;
    }
}