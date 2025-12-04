#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
void print(const T value) { cout << value << "\n"; }

bool isValid(int x, int y, int r, int c) {
    if (x < 0 || x >= r || y < 0 || y >= c) return false;
    return true;
}

class Solution {
private:
    vector<vector<char>> rollsOfPaper;
    vector<pair<int, int>> actions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    int r, c, finalAns = 0;
public:
    Solution(const vector<vector<char>> &rolls) {
        rollsOfPaper = rolls; 
        r = rollsOfPaper.size();
        c = rollsOfPaper[0].size();
    }

    vector<pair<int, int>> solver(vector<vector<char>> &rollsOfPaper) {
        int x, y, counter = 0;
        vector<pair<int, int>> indices = {};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                counter = 0;
                for (auto action : actions) {
                    x = i + action.first; y = j + action.second;
                    if (isValid(x, y, r, c) && rollsOfPaper[x][y] == '@') {
                        counter += 1;
                    }
                }
                if (rollsOfPaper[i][j] == '@' && counter < 4) {
                    indices.push_back({i, j});
                    finalAns += 1;
        }}}
        return indices;
    }

    int solve() {
        while (true) {
            vector<pair<int, int>> indixes = solver(rollsOfPaper);
            if (indixes.size() == 0) break;
            for (auto it: indixes) {
                rollsOfPaper[it.first][it.second] = '.';
            }
        } 
        return finalAns;
    }
};

int main() {
    vector<vector<char>> rollsOfPaper;
    vector<char> rolls;
    ifstream file("data2.txt");
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
    //     {'@', '.', '@', '.', '@', '@', '@', '.', '@', '.'}};
    Solution sol(rollsOfPaper);
    int answer = sol.solve();
    print(answer);
}
