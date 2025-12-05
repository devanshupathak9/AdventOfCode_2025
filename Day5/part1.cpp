#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef long long ll;

vector<pair<ll, ll>> freshRange;
vector<ll> ingredient;

template <typename T>
void print(const T value) { cout << value << "\n"; }

void parseLine(const string &line) {
    if (line.empty()) return;
    size_t ch = line.find('-');

    if (ch != string::npos) {

        string startStr = line.substr(0, ch);
        string endStr = line.substr(ch + 1);

        startStr.erase(remove(startStr.begin(), startStr.end(), ' '), startStr.end());
        endStr.erase(remove(endStr.begin(), endStr.end(), ' '), endStr.end());

        if (!startStr.empty() && !endStr.empty()) {
            try {
                ll start = stoll(startStr);
                ll end = stoll(endStr);
                freshRange.push_back({start, end});
            } catch (const invalid_argument &e) {
                cerr << "Invalid number in range: " << line << endl;
            } catch (const out_of_range &e) {
                cerr << "Number out of range: " << line << endl;
            }
        }
    } else {
        string numStr = line;
        numStr.erase(remove(numStr.begin(), numStr.end(), ' '), numStr.end());

        if (!numStr.empty()) {
            try {
                ll num = stoll(numStr);
                ingredient.push_back(num);
            } catch (const invalid_argument &e) {
                cerr << "Invalid number: " << line << endl;
            } catch (const out_of_range &e) {
                cerr << "Number out of range: " << line << endl;
            }
        }
    }
}

class Solution {
private:
    vector<pair<ll, ll>> frRange;
    vector<ll> ingredient;

public:
    Solution(vector<pair<ll, ll>> &freshRang, vector<ll> &ingredientt) {
        frRange = freshRang;
        ingredient = ingredientt;
    }

    vector<pair<ll, ll>> mergeInterval() {
        sort(frRange.begin(), frRange.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b)
            {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first; });
        vector<pair<ll, ll>> stack;
        for (auto it : frRange) {
            if (stack.empty()) {
                stack.push_back(it);
            } else {
            pair<ll, ll> &last = stack.back();
            if (it.first <= last.second) {
                last.second = max(last.second, it.second);
            } else {
                stack.push_back(it);
        }}
        }
        return stack;
    }

    int binarySearch(vector<pair<ll, ll>> &stack, ll &target) {
        int left = 0, right = stack.size() - 1;
        int result = -1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            pair<ll, ll> curr = stack[mid];
            if (curr.first == target)
                return mid;
            else if ((curr.first > target)) {
                right = mid - 1;
            } else {
                result = mid;
                left = mid + 1;
            }
        }
        return result;
    }

    int freshIngridient() {
        int index, counter = 0;
        vector<pair<ll, ll>> stack = mergeInterval();
        for (int i = 0; i < ingredient.size(); i++) {
            ll target = ingredient[i];
            index = binarySearch(stack, target);
            if (index != -1 && stack[index].first <= target && target <= stack[index].second) {
                counter += 1;
            }
        }
        return counter;
    }

    ll totalFreshIngridient() {
        ll counter = 0;
        vector<pair<ll, ll>> stack = mergeInterval();
        for (int i = 0; i < stack.size(); i++) {
            counter += stack[i].second - stack[i].first + 1;
        }
        return counter;
    }
};

int main() {
    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        parseLine(line);
    }
    file.close();

    // vector<pair<ll,ll>> freshRange =  {{3, 5}, {10, 14}, {16,20}, {12, 18}};
    // vector<ll>ingredient = {1, 5, 8, 11, 17, 32};

    Solution solution(freshRange, ingredient);

    // Part: 1
    // int answer = solution.freshIngridient();
    // print(answer);

    // Part: 2
    ll answer = solution.totalFreshIngridient();
    print(answer);
}