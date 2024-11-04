// 2n students where ai is skill level of ith student
// assign students to 2 classes such that each has odd number of students
// assign in a way that absolute difference in level is minimised
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long testcases = 0;
    cin >> testcases;

    for(long long i = 0; i < testcases; i++){
        long long n;
        cin >> n;

        vector<long long> skills(2*n);
        long long sum = 0;
        for(long long j = 0; j < 2*n; j++){
            cin >> skills[j];
            sum += skills[j];
        }
        
         // Sort the skill levels
        sort(skills.begin(), skills.end());

        // Find the two medians:
        int median1 = skills[n - 1]; // Last element of the first half
        int median2 = skills[n];     // First element of the second half

        // The absolute difference in the medians
        int result = abs(median1 - median2);

        cout << result << '\n';
    }
}