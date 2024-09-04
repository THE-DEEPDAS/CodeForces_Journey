// he wrote 4 numbers a , b , c , d and then choose 2 digits and replaced it with their sum or 
// product. we are also given the 3 operations that he performed in order
// we have to find the minimum number that can be made from that
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll apply_operation(ll x, ll y, char op) {
    if (op == '+') return x + y;
    if (op == '*') return x * y;
    return LLONG_MAX;
}

// so what we do is that till level is not 3 we make all the possible combinations and find min 
// then we left shift the numbers to form a new combination 
void findMinimumNumber(int level, ll numbers[5], char operation1, char operation2, char operation3, ll &minimumNumber) {
    if (level == 3) {
        minimumNumber = min(minimumNumber, numbers[0]);
        return;
    }
    
    ll newNumbers[5];
    for (int i = 0; i < 4 - level; i++) {
        for (int j = i + 1; j < 4 - level; j++) {
            for (int k = 0; k < 5; k++)
                newNumbers[k] = numbers[k];
                
            char operation;
            if (level == 0) operation = operation1;
            else if (level == 1) operation = operation2;
            else if (level == 2) operation = operation3;
            
            newNumbers[i] = apply_operation(newNumbers[i], newNumbers[j], operation);
            
            for (int k = j; k < 4; k++)
                newNumbers[k] = numbers[k + 1];
                
            findMinimumNumber(level + 1, newNumbers, operation1, operation2, operation3, minimumNumber);
        }
    }
}

int main() {
    ll a[5], ans = LLONG_MAX;
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    a[4] = 0;
    
    char op1, op2, op3;
    cin >> op1 >> op2 >> op3;
    
    findMinimumNumber(0, a, op1, op2, op3, ans);
    cout << ans << endl;
}