//n choclates and ai choclates of i type
// also you can take only continuous choclates
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    long long totalChocolates = a[n - 1];
    long long previousChocolates = a[n - 1];
    
    for (long long i = n - 2; i >= 0; i--) {
        long long currentChocolates = a[i];
        
        if(currentChocolates < previousChocolates )  
           {
            totalChocolates += currentChocolates;
            previousChocolates = currentChocolates;
           } 
        else if(currentChocolates >= previousChocolates && previousChocolates > 1){
            totalChocolates += previousChocolates - 1;
            previousChocolates --;
        }
        else{
            break;
        }
    }
    
    cout << totalChocolates << endl;
    return 0;
}

//