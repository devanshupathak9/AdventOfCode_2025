#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
void print(const T value){cout << value << "\n";}

bool isValid(int x, int y, int r , int c) {
    if (x < 0 || x >= r || y <0 || y>=c) return false;
    return true;
}

int solve(vector<vector<char>> &rollsOfPaper) {
    int r = rollsOfPaper.size(), c = rollsOfPaper[0].size();
    int x, y, counter = 0, finalAns = 0;
    vector<pair<int, int>>actions = {
        {1, 0}, 
        {0, 1}, 
        {-1, 0}, 
        {0, -1}, 
        {1, 1}, 
        {-1, -1}, 
        {1, -1}, 
        {-1, 1}
    };

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            counter = 0;
            for(auto action: actions) {
                x = i + action.first; y = j + action.second;
                if (isValid(x, y, r, c) && rollsOfPaper[x][y] == '@') {
                    counter += 1;
            }}
            if (rollsOfPaper[i][j] == '@' && counter < 4) finalAns += 1;
        }
    }
    return finalAns;
}

int main() {
    vector<vector<char>> rollsOfPaper;
    vector<char> rolls;
    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        rolls = {};
        for(auto it: line) rolls.push_back(it);
        rollsOfPaper.push_back(rolls);
    }
    file.close();

    // vector<vector<char>> rollsOfPaper = {
    //     {'.', '.', '@', '@', '.', '@', '@', '@', '@', '.'},
    //     {'@', '@', '@', '.', '@', '.', '@', '.', '@', '@'},
    //     {'@', '@', '@', '@', '@', '.', '@', '.', '@', '@'},
    //     {'@', '.', '@', '@', '@', '@', '.', '.', '@', '.'},
    //     {'@', '@', '.', '@', '@', '@', '@', '.', '@', '@'},
    //     {'.', '@', '@', '@', '@', '@', '@', '@', '.', '@'},
    //     {'.', '@', '.', '@', '.', '@', '.', '@', '@', '@'},
    //     {'@', '.', '@', '@', '@', '.', '@', '@', '@', '@'},
    //     {'.', '@', '@', '@', '@', '@', '@', '@', '@', '.'},
    //     {'@', '.', '@', '.', '@', '@', '@', '.', '@', '.'}
    // };
    int answer = solve(rollsOfPaper);
    print(answer);
}