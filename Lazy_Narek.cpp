#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int calculate_score(string &s) {
    vector<int> cnt(5, 0); 
    for (char c : s) {
        if (c == 'n') cnt[0]++;
        else if (c == 'a') cnt[1]++;
        else if (c == 'r') cnt[2]++;
        else if (c == 'e') cnt[3]++;
        else if (c == 'k') cnt[4]++;
    }
    return cnt[0];
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;

        vector<string> strings(n);
        for (ll i = 0; i < n; ++i) {
            cin >> strings[i];
        }

        ll max_score_diff = 0;

        for (const string &s : strings) {
            ll chat_score = 0;
            ll narek_score = 0;
            ll len = s.size();

            for (ll start = 0; start < len; ++start) {
                vector<int> cnt(5, 0); 
                bool found_n = false, found_a = false, found_r = false, found_e = false, found_k = false;
                for (ll i = start; i < len; ++i) {
                    if (s[i] == 'n') {
                        found_n = true;
                        cnt[0]++;
                    } else if (s[i] == 'a' && found_n) {
                        found_a = true;
                        cnt[1]++;
                    } else if (s[i] == 'r' && found_a) {
                        found_r = true;
                        cnt[2]++;
                    } else if (s[i] == 'e' && found_r) {
                        found_e = true;
                        cnt[3]++;
                    } else if (s[i] == 'k' && found_e) {
                        found_k = true;
                        cnt[4]++;
                    }

                    if (found_k) {
                        narek_score += 5;
                        found_n = found_a = found_r = found_e = found_k = false;
                    }
                }
                chat_score = cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4];
                max_score_diff = max(max_score_diff, narek_score - chat_score);
            }
        }

        cout << max_score_diff << endl;
    }
}
