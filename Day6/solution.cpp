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
    for (auto it: vec) cout << it << "~";
    cout << "\n";
}

vector<vector<string>>values;
vector<char> operation;

void parseLine(string &line) {
    if (line.empty()) return;

    stringstream ss(line);
    string word;
    vector<string> words;
    bool isOperatorLine = true;

    while (ss >> word) {
        if (word == "+" || word == "*") {
            operation.push_back(word[0]);
        } else {
            isOperatorLine = false;
            words.push_back(word);
        }
    }
    if (!isOperatorLine && !words.empty()) {
        values.push_back(words);
    }
}


ll solve() {
    ll answer = 0;
    for (int i = 0; i < values[0].size(); i++) {
        char op = operation[i];
        ll mathValue = (op == '*') ? 1 : 0;

        for (int j = 0; j < values.size(); j++) {
            ll v = stoll(values[j][i]);
            if (op == '*') mathValue *= v;
            else mathValue += v;
        }
        answer += mathValue;
    }
    return answer;
}


int main() {
    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        parseLine(line);
    }
    file.close();

    // Part: 1
    ll answer = solve();
    print(answer);
    return 0;
}