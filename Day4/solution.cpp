#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
void print(const T& value) { cout << value << "\n"; }

bool isValid(int x, int y, int r , int c) {
    if (x < 0 || x >= r || y < 0 || y >= c) 
        return false;
    return true;
}

class Solution {
private:
    int n, m;
    vector<string> grid;
    vector<pair<int, int>> actions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}, 
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };
public: 
    Solution(const vector<string>& g) : grid(g) {
        n = grid.size();
        m = grid[0].size();
    }

    int solveP1() {
        int counter = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    int rollCounter = 0;
                    for(auto action: actions) {
                        int x = i + action.first;
                        int y = j + action.second;
                        if (isValid(x, y, n, m) && grid[x][y] == '@'){
                            rollCounter += 1;
                        }
                    }
                    if (rollCounter < 4) { counter += 1; }
                }
            }
        }
        return counter;
    }

    int findAccessibleRolls() {
        vector<pair<int,int>> toRemove;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
    
                    int rollCounter = 0;
                    for(auto action : actions) {
                        int x = i + action.first;
                        int y = j + action.second;
    
                        if (isValid(x, y, n, m) && grid[x][y] == '@')
                            rollCounter++;
                    }
                    if (rollCounter < 4)
                        toRemove.push_back({i, j});
                }
            }
        }
    
        for(auto &p : toRemove)
            grid[p.first][p.second] = '.';
        return toRemove.size();
    }
    
    int solveP2() {
        int finalRes = 0;
        while (1) {
            int res = findAccessibleRolls();
            if (res == 0) break;
            finalRes += res;
        }
        return finalRes;
    }

};

int main() {
    
    string line;
    vector<string> grid;
    ifstream file("data.txt");
    while (getline(file, line)) {
        if (!line.empty())
            grid.push_back(line);
    }
    file.close();
    Solution sol(grid);
    int res1 = sol.solveP1();
    print(res1);
    
    Solution sol2(grid);
    int res2 = sol2.solveP2();
    print(res2);
    return 0;
}