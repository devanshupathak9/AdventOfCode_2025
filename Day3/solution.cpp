#include <iostream>
#include <vector>
#include <fstream>
#include<string>
using namespace std;
typedef long long ll;

template <typename T>
void print(T value) { cout << value << "\n"; }

int findMaxValue(const string &bank, int start, int end) {
    int maxIdx = -1;
    int maxVal = -1;
    for (int i = start; i <= end; i++) {
        if (bank[i] - '0' > maxVal) {
            maxVal = bank[i] - '0';
            maxIdx = i;
        }
    }
    return maxIdx;
}

class Solution {
public: 
    int findMaxJoltValueP1(string bank) {
        int nxtIndex = 0;
        int maxJoltValue = 0;
        for(int i = 0; i < 2; i++) {
            int currIndex = findMaxValue(bank, nxtIndex, bank.size() - 2 + i);
            nxtIndex = currIndex + 1;
            maxJoltValue = maxJoltValue*10 + (bank[currIndex] - '0');
        }
        return maxJoltValue;
    }
    ll findMaxJoltValueP2(string bank) {
        int nxtIndex = 0;
        ll maxJoltValue = 0;
        for(int i = 0; i < 12; i++) {
            int currIndex = findMaxValue(bank, nxtIndex, bank.size() - 2 + i);
            nxtIndex = currIndex + 1;
            maxJoltValue = maxJoltValue*10 + (bank[currIndex] - '0');
        }
        return maxJoltValue;
    }
    int solveP1(vector<string>banks) {
        int totalOutputJoltage = 0;
        for(auto bank: banks) {
            int maxJoltValue = findMaxJoltValueP1(bank);
            totalOutputJoltage += maxJoltValue;
        }
        return totalOutputJoltage;
    }
    ll solveP2(vector<string>banks) {
        ll totalOutputJoltage = 0;
        for(auto bank: banks) {
            ll maxJoltValue = findMaxJoltValueP2(bank);
            totalOutputJoltage += maxJoltValue;
        }
        return totalOutputJoltage;
    }
};

int main() {
    Solution sol;
    string s;
    vector<string>banks;
    ifstream file("data.txt");
    while (getline(file, s)) {
        banks.push_back(s);
    }
    file.close();

    int res1 = sol.solveP1(banks);
    print(res1);
    ll res2 = sol.solveP2(banks);
    print(res2);
    return 0;
}