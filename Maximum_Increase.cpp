//find maximum length of increasing subarray

/*
 * @brief Finds the maximum length of an increasing subarray in a given array.
 *
 * @param numbers The size of the input array.
 * @param inputs The input array containing integers.
 *
 * @return The maximum length of an increasing subarray in the input array.
 */
#include<bits/stdc++.h>

using namespace std;


int main(){
    int numbers = 0;
    cin >> numbers;

    vector<int> inputs(numbers);
    for(int i = 0; i < numbers; i++){
        cin >> inputs[i];
    }

    int maxLength = 1;
    for(int i = 0; i < numbers; i++){
        int current_length = 1;
        for (int j = i; j < numbers - 1; j++){
            if(inputs[j] < inputs[j+1]){
                current_length ++;
                i = j + 1;
            }
            else break;
        }
        maxLength = max(maxLength, current_length);
    }
    cout << maxLength << endl;
}