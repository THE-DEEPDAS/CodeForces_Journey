//only numbers to be summed = 1 , 2 , 3
//sum only of non-decreasing numbers
//just need to sort it

#include<bits/stdc++.h>

using namespace std;


int main(){
    string str;
    cin >> str;

    int count1 = 0 , count2 = 0 , count3 = 0;
    for(char c : str){
        if(c == '1'){
            count1 ++;
        }
        else if(c == '2'){
            count2 ++;
        }
        else if(c == '3'){
            count3 ++;
        }
    }

    // Print numbers with a plus sign between them
     // Print '1' count1 times
    for (int i = 0; i < count1; ++i) {
        cout << "1";
        if (i < count1 - 1 || count2 > 0 || count3 > 0) {
            cout << "+";
        }
    }

    // Print '2' count2 times
    for (int i = 0; i < count2; ++i) {
        cout << "2";
        if (i < count2 - 1 || count3 > 0) {
            cout << "+";
        }
    }

    // Print '3' count3 times
    for (int i = 0; i < count3; ++i) {
        cout << "3";
        if (i < count3 - 1) {
            cout << "+";
        }
    }
    
    cout << endl;
}