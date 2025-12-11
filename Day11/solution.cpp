#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

unordered_map<string, vector<string>>deviceDict;

template <typename T>
void print(const T& value) { cout << value << endl; }

pair<string, vector<string>> parseLine(const string& token) {
    if (token.empty()) return {};
    size_t colon = token.find(':');
    string key = token.substr(0, colon);
    string value = token.substr(colon+2);
    stringstream ss(value);

    string val;
    vector<string> values;
    while (getline(ss, val, ' ')) {
        values.push_back(val);
    }
    return make_pair(key, values);
}

int solvePart1() {
    int counter = 0;
    queue<string>q;
    unordered_set<string>visited;
    q.push("you");
    visited.insert("you");
    while (q.size()) 
    {
        string nextDevice = q.front(); q.pop();
        vector<string> outputs = deviceDict[nextDevice];
        for(auto output: outputs) {
            if (output == "out") counter +=1;
            else {
                q.push(output);
                visited.insert(output);
            }
        }
    }
    return counter;
}

void dfs(const string &node, const string &target, vector<string> &path, vector<vector<string>> &paths, unordered_set<string> &visited) {
    if (node == target) {
        paths.push_back(path);
        return;
    }

    for (const string &next : deviceDict[node]) {
        if (!visited.count(next)) {
            visited.insert(next);
            path.push_back(next);

            dfs(next, target, path, paths, visited);

            path.pop_back();
            visited.erase(next);
        }
    }
}

int solvePart2(string node, string target) {
    vector<vector<string>> all_paths;
    vector<string> path = {"svr"};
    unordered_set<string> visited = {"svr"};

    dfs("svr", "out", path, all_paths, visited);

    cout << "All paths from svr to out:\n";
    for (auto &p : all_paths) {
        for (int i = 0; i < p.size(); i++) {
            cout << p[i] << (i + 1 < p.size() ? "," : "");
        }
        cout << "\n";
    }

    int count = 0;
    cout << "\nPaths that contain both dac and fft:\n";
    for (auto &p : all_paths) {
        bool has_dac = false, has_fft = false;
        for (auto &node : p) {
            if (node == "dac") has_dac = true;
            if (node == "fft") has_fft = true;
        }
        if (has_dac && has_fft) {
            count++;
            for (int i = 0; i < p.size(); i++)
                cout << p[i] << (i + 1 < p.size() ? "," : "");
            cout << "\n";
        }
    }

    cout << "\nNumber of valid paths: " << count << "\n";

    return 0;
}


int main() {
    ifstream file("data.txt");
    string token;
    while (getline(file, token)) {
        pair<string, vector<string>> p = parseLine(token);
        deviceDict[p.first] = p.second;
    }
    file.close();

    int answerPart1 = solvePart1();
    print(answerPart1);

    int answerPart2 = solvePart2("svr", "out");
    print(answerPart2);
    return 0;
}