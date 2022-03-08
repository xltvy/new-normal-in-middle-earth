#include "Character.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    vector<string> operations;
    string line;
    ifstream input("input.txt");
    input.open();
    if (input.is_open()) {
        while (getline(input, line)) {
            operations.push_back(line);
        }
    }
    input.close();
    for (int i=0; i<operations.size(); i++) {
        cout << operations.at(i) << endl;
    }
    int nMaxRounds;

    return 0;
}