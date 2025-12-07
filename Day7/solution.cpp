#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

template <typename T>
void print(const T value) { cout << value << " "; }

template <typename T>
void println(const T value) { cout << value << endl; }

vector<char> parseLine(string &line) {
    if (line.empty())
        return {};
    vector<char> row;
    for (auto it : line)
        row.push_back(it);
    return row;
}

bool check(int r, int c, int x, int y) {
    if (x >= 0 && x < r && y >= 0 && y < c)
        return true;
    return false;
}

int solve(vector<vector<char>> &grid) {
    queue<pair<int, int>> queue;
    int splitter = 0;
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    for (int j = 0; j < c; j++) {
        if (grid[0][j] == 'S') {
            queue.push({0, j});
            break;
        }
    }
    int x, y;
    while (!queue.empty()) {
        pair<int, int> pos = queue.front();
        queue.pop();
        x = pos.first;
        y = pos.second;
        if (check(r, c, x + 1, y) && grid[x + 1][y] == '.') {
            if (check(r, c, x, y) && visited[x + 1][y] == false) {
                queue.push({x + 1, y});
                visited[x + 1][y] = true;
            }
        }
        else if (check(r, c, x + 1, y) && grid[x + 1][y] == '^') {
            splitter += 1;
            if (check(r, c, x + 1, y + 1) && visited[x + 1][y + 1] == false) {
                queue.push({x + 1, y + 1});
                visited[x + 1][y + 1] = true;
            }
            if (check(r, c, x + 1, y - 1)) {
                queue.push({x + 1, y - 1});
                visited[x + 1][y - 1] = true;
            }
        }
    }
    return splitter;
}

int main()
{
    vector<vector<char>> grid;
    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        vector<char> row = parseLine(line);
        grid.push_back(row);
    }
    file.close();
    int answer = solve(grid);
    println(answer);
    return 0;
}