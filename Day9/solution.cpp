#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <queue>
using namespace std;
using ll = long long;

template<typename T>
void print(const T& value) { cout << value << endl; }

pair<ll, ll> parseLine(string line) {
    size_t pos = line.find(',');
    ll x = stoll(line.substr(0, pos));
    ll y = stoll(line.substr(pos+1));
    return make_pair(x, y);
}

double findDistance(string line1, string line2) {
    pair<ll, ll> p1 = parseLine(line1);
    pair<ll, ll> p2 = parseLine(line2);
    ll dx = p1.first - p2.first;
    ll dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

ll findArea(string line1, string line2) {
    pair<ll, ll> p1 = parseLine(line1);
    pair<ll, ll> p2 = parseLine(line2);
    ll dx = p1.first - p2.first + 1;
    ll dy = p1.second - p2.second + 1;
    return dx*dy;
}

ll solvePart1(vector<string>& coordinates) {
    priority_queue<pair<ll, pair<string, string>>>pq;
    for(int i = 0; i<coordinates.size(); i++) {
        for(int j = i+1; j<coordinates.size(); j++) {
            int area = findArea(coordinates[i], coordinates[j]);
            pq.push(make_pair(dist, make_pair(coordinates[i], coordinates[j])));
        }  
    }
        pair<double, pair<string, string>>p = pq.top(); pq.pop();
        maxArea = max(maxArea, findArea(p.second.first, p.second.second));
    }
    return maxArea;
}

int main() {
    vector<string> lines;
    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    ll answer = solvePart1(lines);
    print(answer);

    // int answer = solvePart2(coordinates);
    // print(answer);
    return 0;
}