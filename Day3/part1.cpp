#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
void print(T value) { cout << value; }

template <typename T>
void println(T value) { cout << value << "\n"; }

int solve(vector<string> &banks)
{
    int n = banks.size();
    int totalOutputJoltage = 0;
    int maxFirst = -1, maxSecond = -1, maxJolt = 0;
    for (auto bank : banks) {
        maxFirst = 0;
        maxSecond = 0;
        maxJolt = 0;
        for (auto it : bank) {
            int digit = it - '0';
            if (maxFirst != 0 && digit > maxSecond) {
                maxSecond = digit;
            }
            if (maxFirst * 10 + maxSecond > maxJolt) {
                maxJolt = maxFirst * 10 + maxSecond;
            }
            if (digit > maxFirst) {
                maxFirst = digit;
                maxSecond = 0;
                continue;
            }
        }
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

    int totalOutputJoltage = solve(banks);
    print("totalOutputJoltage: ");
    println(totalOutputJoltage);
}