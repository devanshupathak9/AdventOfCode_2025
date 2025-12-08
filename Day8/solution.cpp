// How to solve:
// 1. Parse each line as a 3D coordinate (X,Y,Z).
// 2. For every unique pair of junction boxes, compute their (Euclidean) distance.
// 3. Insert all pairs as edges with their distances into a min-heap/priority_queue.
// 4. Use a Disjoint Set data structure to keep track of which boxes are in the same circuit.
// 5. For Part 1: Keep connecting the closest boxes (edges) until you've made the required number of connections,
//    then multiply the sizes of the three largest resulting circuits.
// 6. For Part 2: Continue the process until there is only one circuit (all boxes connected).
//    Track the last two boxes connected, and return the product of their X coordinates.

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include <set>
#include<unordered_map>
using namespace std;

template<typename T>
void print(T value) { cout << value << endl; }

template<typename T>
void printvec(const vector<T>& vec) { 
    for(auto it: vec) cout << it << " | ";
    cout <<endl;
}

template<typename... Args>
void println(const Args&... args) {
    ((cout << args << " "), ...);
    cout << endl;
}

class DisjointSet {
    private:
        unordered_map<string, string>ds;
        unordered_map<string, int>sz;
    public:
        DisjointSet(const vector<string>& lines) {
            for(auto it: lines) {
                ds[it] = it;
                sz[it] = 1;
            }
        }

        void makeUnion(string line1, string line2) {
            string root1 = findNode(line1);
            string root2 = findNode(line2);
            if (root1 == root2) return;
            if (sz[root1] > sz[root2]) {
                swap(root1, root2);
            }
            ds[root1] = root2;
            sz[root2] += sz[root1];
        }

        string findNode(string s) {
            if (ds[s] == s) return s;
            return ds[s] = findNode(ds[s]);
        }

        int getSize(string s) {
            return sz[findNode(s)];
        }
};

vector<int> parseLine(const string& line) {
    vector<int> coordinates;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ',')) {
        coordinates.push_back(stoi(token));
    }
    return coordinates;
}

double euclideanDistance(string line1, string line2) {
    vector<int> lin1 = parseLine(line1);
    vector<int> lin2 = parseLine(line2);
    int dist = 0;
    for (int i = 0; i<lin1.size(); i++) {
        dist += pow(lin1[i] - lin2[i], 2);
    }
    return sqrt(dist);
}

int solvePart1(vector<string>&lines) {
    priority_queue<pair<double, pair<string, string>>>pq;
    string line1, line2;
    double distance;
    for (int i = 0; i<lines.size(); i++) {
        line1 = lines[i];
        for(int j = i+1; j<lines.size(); j++){
            line2 = lines[j];
            distance = euclideanDistance(line1, line2);
            pq.push(make_pair(-1*distance, make_pair(line1, line2)));

        }
    }

    DisjointSet disjoinSet(lines);
    int iteration = 1000;
    while (iteration--) {
        if (!pq.size()) break;
        pair<double, pair<string, string>>p = pq.top(); pq.pop();
        line1 = p.second.first;
        line2 = p.second.second;
        disjoinSet.makeUnion(line1, line2);
    }

    set<string> nodes;
    priority_queue<int> sizes;
    for(int i = 0; i<lines.size(); i++) {
        string line = lines[i];
        string node = disjoinSet.findNode(line);
        int size = disjoinSet.getSize(node);
       
        if (nodes.find(node)==nodes.end()) {
            nodes.insert(node);
            sizes.push(size);
        }
    }
    int topThree = 3;
    int answer = 1;
    while (topThree--) {
        answer = answer*sizes.top(); 
        sizes.pop();
    }
    return answer;
}

int solvePart2(const vector<string>& lines) {
    priority_queue<pair<double, pair<string, string>>>pq;
    double distance;
    string line1, line2;
    for (int i = 0; i<lines.size(); i++) {
        line1 = lines[i];
        for(int j = i+1; j<lines.size(); j++) {
            line2 = lines[j];
            distance = euclideanDistance(line1, line2);
            pq.push(make_pair(-1*distance, make_pair(line1, line2)));
        }
    }

    DisjointSet disjoinSet(lines);
    while (true) {
        if (!pq.size()) break;
        pair<double, pair<string, string>>p = pq.top(); 
        pq.pop();
        line1 = p.second.first;
        line2 = p.second.second;
        disjoinSet.makeUnion(line1, line2);
        if (disjoinSet.getSize(line1) == lines.size()) break;
    }
    vector<int> lastNode1 = parseLine(line1);
    vector<int> lastNode2 = parseLine(line2);
    return lastNode1[0]*lastNode2[0];
}

int main() {
    vector<string>lines;
    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    int answer1 = solvePart1(lines);
    print(answer1);

    int answer2 = solvePart2(lines);
    print(answer2);
    return 0;
}