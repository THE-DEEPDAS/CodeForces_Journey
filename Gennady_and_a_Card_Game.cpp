// check if we can play atleast one card
#include<bits/stdc++.h>

using namespace std;


int main(){
    string tableCard;
    cin >> tableCard;

    vector<string> myCard(5);
    for(int i = 0; i < 5; i++){
        cin >> myCard[i];
    }

    bool found = false;
    for(string card : myCard){
        if(card[0] == tableCard[0] || card[1] == tableCard[1]){
            cout << "YES" << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << "NO" << endl;   
}