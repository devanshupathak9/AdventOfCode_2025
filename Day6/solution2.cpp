#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

typedef long long ll;

template <typename T> 
void print(const T value) { cout << value << "\n"; }

template <typename T> 
void printvec(vector<T> vec) {
    for (auto it: vec) cout << it << " ";
    cout << "\n";
}

vector<vector<char>>grid;
vector<char> operation;

void parseLine(const string& line) {
    if (line.find('+') != string::npos || line.find('*') != string::npos) {
        for (char c : line) {
            if (c == '+' || c == '*')
                operation.push_back(c);
        }
    } else if (!line.empty()) {
        vector<char>ch;
        for (auto it: line) {
            ch.push_back(it);
        }
        grid.push_back(ch);
    }
}

ll solve() {
    ll total = 0, num = 0;
    int rows = grid.size();
    int col = grid[0].size() - 1;
    int opIndex = operation.size() - 1;

    vector<ll> numbers;

    while (col >= 0) {
        bool hasDigit = false;
        num = 0;
        for (int r = 0; r < rows; r++) {
            if (isdigit(grid[r][col])) {
                num = num * 10 + (grid[r][col] - '0');
                hasDigit = true;
            }
        }
        if (!hasDigit) {
            char op = operation[opIndex--];
            ll value = (op == '*') ? 1 : 0;
            // printvec(numbers);
            for (ll n : numbers) {
                if (op == '*' && n!=0) value *= n;
                if (op == '+') value += n;
            }
            print(value);
            total += value;
            numbers = {};
        }
        numbers.push_back(num);
        col--;
    }
    char op = operation[opIndex--];
    ll value = (op == '*') ? 1 : 0;
    printvec(numbers);
    for (ll n : numbers) {
        if (op == '*' && n!=0) value *= n;
        if (op == '+') value += n;
    }

    total += value;
    numbers = {};

    return total;
}


int main() {
    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        parseLine(line);
    }
    file.close();

    // Part: 2
    ll answer = solve();
    print(answer);
    return 0;
}