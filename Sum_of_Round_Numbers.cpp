#include<bits/stdc++.h>

using namespace std;


int main(){
 int testcases = 0;
 cin >> testcases;

 while(testcases--){
        int testcase = 0;
        cin >> testcase;

        vector<int> answer;
        int i = 0;
        while (testcase > 0){
            if((testcase % 10) != 0){
                answer.push_back((testcase % 10) * pow(10,i));
            }
            testcase /= 10;
            i++;
        }
        int answer_size = answer.size();
        cout << answer_size << endl;
        for (int i = 0; i < answer_size ; i++){
            cout << answer[i] << " ";
        }
        cout << endl;
    } 
}