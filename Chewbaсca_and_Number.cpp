#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long integer = 0,answer = 1.0;
    cin >> integer;

    // special case for input  = 0
    if (integer == 0) {
        cout << 0 << endl;
        return 0;
    }

    string num = to_string(integer);
    int len = num.length();

    // check 1st digit as condition is it can't be 0
    if (num[0] != '9' && '9' - num[0] < num[0] - '0') {
        num[0] = '9' - num[0] + '0'; // we do + '0' here because to convert it to string again from number
    }

    // Process the rest of the digits
    for (int i = 1; i < len; ++i) {
        if ('9' - num[i] < num[i] - '0') {
            num[i] = '9' - num[i] + '0';
        }
    }

    cout << num << endl;
}