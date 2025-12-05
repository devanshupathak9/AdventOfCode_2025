#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

using ll  = long long;

template <typename T>
void print(T value) { cout << value; }

template <typename T>
void println(T value) { cout << value << "\n"; }

int findMaxIndex(string bank, int start, int end) {
    int maxDigit = 0, index;
    for (int i = start; i <= end; i++) {
        int digit = bank[i] - '0';
        if (digit > maxDigit) {
            maxDigit = digit; 
            index = i;
        } 
    }
    return index;
}

ll solve(vector<string>& banks)
{
    ll totalOutputJoltage = 0, maxJolt = 0;
    int n, ind, lastIndex;
    for (auto bank : banks) {
        n = bank.size();
        maxJolt = 0;
        lastIndex = 0;
        for(int i = 0; i<12; i++) 
        {
            ind = findMaxIndex(bank, lastIndex, n - 12 + i);
            maxJolt = maxJolt*10 + bank[ind] - '0';
            lastIndex = ind + 1;
        }
        println(maxJolt);
        totalOutputJoltage += maxJolt;
    }
    return totalOutputJoltage;
}

int main()
{
    // vector<string>banks = {
    //     "987654321111111",
    //     "811111111111119",
    //     "234234234234278",
    //     "818181911112111"
    // };

    vector<string> banks;
    ifstream file("data.txt");
    string line;
    while (getline(file, line))
    {
        banks.push_back(line);
    }
    file.close();

    ll totalOutputJoltage = solve(banks);
    print("totalOutputJoltage: ");
    println(totalOutputJoltage);
}