#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Define the test cases
    vector<string> testcases = {
        "7 976\n1268 5636 2973 2567 2475 3719 1799",
        "2 462\n950 8187",
        "9 423\n6069 365 6112 3486 3279 6674 4284 9271 8110",
        "3 543\n3040 2234 1797",
        "8 579\n3604 5452 2079 8916 7552 4067 9037 312",
        "6 695\n8774 6512 8113 739 1711 8027",
        "4 396\n2047 5837 9172 1676",
        "6 126\n8351 4235 6568 6582 5398 6012",
        "5 974\n7583 7394 1831 6731 830",
        "10 658\n9493 1106 96 4515 3062 4868 3340 9150 3025 7513"
    };

    // Save each test case to a separate file
    for (size_t i = 0; i < testcases.size(); ++i) {
        string filename = "testcase_" + to_string(i + 1) + ".txt";
        ofstream outfile(filename);

        if (outfile.is_open()) {
            outfile << testcases[i];
            outfile.close();
            cout << "Saved test case " << i + 1 << " to " << filename << endl;
        } else {
            cerr << "Error: Unable to open file " << filename << endl;
        }
    }

    return 0;
}
