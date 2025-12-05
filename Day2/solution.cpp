#include<iostream>
#include<vector>
#include<string>
#include <fstream>
using namespace std;
#define mod 1000000007

using ll = long long;
using ld  = long double;

template <typename T>
void print(const T& value) {cout << value <<"\n";}

template <typename T>
void println(const T& value) {cout << value << "\n";}

ll solve(vector<string>&ranges) {
    ll totalInvalid = 0;
    for(auto str: ranges) {
        size_t dashIndex = str.find('-');
        ll num1 = stoll(str.substr(0, dashIndex));
        ll num2 = stoll(str.substr(dashIndex + 1));

    }
}

int main() {
    // vector<string> actions;
    // ifstream file("data.txt");
    // string line;
    // while (getline(file, line))
    // {
    //     actions.push_back(line);
    // }
    // file.close();
    vector<string> ranges = {"11-22", "95-115", "998-1012", "1188511880-1188511890", "222220-222224",
        "1698522-1698528", "446443-446449", "38593856-38593862", "565653-565659",
        "824824821-824824827", "2121212118-2121212124"};
    ll answer = solve(ranges);
    print(answer);
    return 0;
}