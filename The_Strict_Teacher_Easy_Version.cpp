#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll testcases;
    cin >> testcases;

    while(testcases--){
        ll n, m, q;
        cin >> n >> m >> q;

        ll teacher_pos_1, teacher_pos_2;
        cin >> teacher_pos_1 >> teacher_pos_2;
        ll our_pos;
        cin >> our_pos;

        if(teacher_pos_1 > teacher_pos_2) swap(teacher_pos_1, teacher_pos_2);
        ll ans = 0;
        if(our_pos < teacher_pos_1){
            ans = teacher_pos_1 - 1;
        }
        else if(our_pos > teacher_pos_2){
            ans = n - teacher_pos_2;
        }
        else{
            ll median = (ceil(teacher_pos_1 + teacher_pos_2) / 2);
            ans = min(teacher_pos_2 - median, median - teacher_pos_1);
        }
        cout << ans << endl;
    }
}