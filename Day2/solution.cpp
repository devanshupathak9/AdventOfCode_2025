#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include<sstream>
using namespace std;
#define mod 1000000007

using ll = long long;
using ld  = long double;

template <typename T>
void print(const T& value) {cout << value << "\n";}

template <typename T> 
void printvec(vector<T> vec) {
    for (auto it: vec) cout << it << " ";
    cout << "\n";
}

vector<pair<string, string>> parseLine(const string&line) {
    vector<pair<string, string>> vect;
    if (line.empty()) return {};
    stringstream ss(line);
    string token;
    while (getline(ss, token, ',')) {
        size_t ind = token.find('-');
        string num1 = token.substr(0, ind);
        string num2 = token.substr(ind + 1);
        vect.push_back({num1, num2});
    }
    return vect;
}


ll solve(vector<pair<string, string>>range) {
    ll totalInvalid = 0;
    string lower, upper;
    for(auto p: range) {
        lower = p.first;
        upper = p.second;
        if (lower.size()%2 == 1 && upper.size()%2 == 1) continue;
    }
}

int main() {
    vector<pair<string, string>>range;
    ifstream file("data.txt");
    string line;
    while (getline(file, line))
    {
        range = parseLine(line);
    }
    file.close();

    ll answer = solve(range);
    print(answer);
    return 0;
}