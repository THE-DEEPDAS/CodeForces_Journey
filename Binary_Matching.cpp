#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();
        string s;
        cin >> s;
        int r = 0;
        int l = 0;
        if (s[0] == s[n - 1])
        {
            cout << 0 << endl;
        }
        else
        {
            if(s[1] == '1' && s[n - 2] == '1'){
                cout << 2 << endl;
            }
            else{
                cout << 1 << endl;
            }
        }
    }
}