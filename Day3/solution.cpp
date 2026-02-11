#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
typedef long long ll;

template <typename T>
void print(T value) {
    cout << value << "\n";
}

int returnMaxIndex(const string &bank, int start, int end) {
    int maxIdx = -1;
    int maxVal = -1;
    for (int i = start; i < end; i++) {
        if (bank[i] - '0' > maxVal) {
            maxVal = bank[i] - '0';
            maxIdx = i;
        }
    }
    return maxIdx;
}

class Solution {
public:
    int findMaxJoltP1(const string &bank) {
        int nxtIndex = 0;
        int maxJolt = 0;
        for (int i = 0; i < 2; i++) {
            int currIndex = returnMaxIndex(bank, nxtIndex, bank.size() - 2 + i + 1);
            nxtIndex = currIndex + 1;
            maxJolt = maxJolt * 10 + (bank[currIndex] - '0');
        }
        return maxJolt;
    }
    ll findMaxJoltP2(const string &bank) {
        int nxtIndex = 0;
        ll maxJolt = 0;
        for (int i = 0; i < 12; i++) {
            int currIndex = returnMaxIndex(bank, nxtIndex, bank.size() - 2 + i + 1);
            nxtIndex = currIndex + 1;
            maxJolt = maxJolt * 10 + (bank[currIndex] - '0');
        }
        return maxJolt;
    }

    int solveP1(const vector<string> &banks) {
        int totalOutputJoltage = 0;
        for (auto &bank : banks) {
            int maxJolt = findMaxJoltP1(bank);
            totalOutputJoltage += maxJolt;
        }
        return totalOutputJoltage;
    }
    ll solveP2(const vector<string> &banks) {
        ll totalOutputJoltage = 0;
        for (auto &bank : banks) {
            ll maxJolt = findMaxJoltP2(bank);
            totalOutputJoltage += maxJolt;
        }
        return totalOutputJoltage;
    }
};

int main()
{
    Solution sol;

    string s;
    vector<string> banks;
    ifstream file("data.txt");
    while (getline(file, s)) {
        banks.push_back(s);
    }
    file.close();

    int res1 = sol.solveP1(banks);
    ll res2 = sol.solveP2(banks);
    print(res1);
    print(res2);
    return 0;
}
