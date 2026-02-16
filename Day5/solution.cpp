#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
typedef long long ll;

template <typename T>
void print(T value) { cout << value << "\n"; }

class Solution {
private:
    vector<ll> availableIngredient;
    vector<pair<ll, ll>> ingredientRange;

public:
    Solution(vector<ll> &availableIng,
             vector<pair<ll, ll>> &ingredientR)
        : availableIngredient(availableIng),
          ingredientRange(ingredientR)
    {
        if (!ingredientRange.empty()) {
            sort(ingredientRange.begin(), ingredientRange.end(),
                 [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
                     if (a.first == b.first)
                         return a.second < b.second;
                     return a.first < b.first;
                 });
        }
    }

    bool checkFreshIngridient(ll ingredient, vector<pair<ll, ll>> &mergedIngredientRange)
    {
        int mid;
        int result = -1;
        int start = 0;
        int end = mergedIngredientRange.size() - 1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (mergedIngredientRange[mid].first == ingredient)
                return true;
            if (mergedIngredientRange[mid].first > ingredient) {
                end = mid - 1;
            }
            else if (mergedIngredientRange[mid].first < ingredient) {
                result = mid;
                start = mid + 1;
            }
        }
        if (ingredient >= mergedIngredientRange[result].first && ingredient <= mergedIngredientRange[result].second) {
            return true;
        }
        return false;
    }

    vector<pair<ll, ll>> mergeIngredient(vector<pair<ll, ll>> &ranges) {
        vector<pair<ll, ll>> result;
        if (ranges.empty())
            return result;

        result.push_back(ranges[0]);
        for (int i = 1; i < ranges.size(); i++) {
            pair<ll, ll> curr = ranges[i];
            pair<ll, ll> &back = result.back();
            if (curr.first > back.second) {
                result.push_back(curr);
            }
            else {
                back.second = max(curr.second, back.second);
            }
        }
        return result;
    }

    ll solveP1() {
        ll counter = 0;
        vector<pair<ll, ll>> mergedIngredientRange = mergeIngredient(ingredientRange);

        for (auto it : availableIngredient) {
            if (checkFreshIngridient(it, mergedIngredientRange)) {
                counter++;
            }
        }
        return counter;
    }

    ll solveP2() {
        ll counter = 0;
        vector<pair<ll, ll>> mergedIngredientRange = mergeIngredient(ingredientRange);

        for (auto it : mergedIngredientRange) {
            counter += it.second - it.first + 1;
        }
        return counter;
    }
};

pair<ll, ll> parseLine(const string &line) {
    size_t index = line.find('-');
    if (index == string::npos) {
        throw invalid_argument("No '-' found in line");
    }
    string s1 = line.substr(0, index);
    string s2 = line.substr(index + 1);
    s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());
    s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());
    if (s1.empty() || s2.empty()) {
        throw invalid_argument("Empty substring after parsing");
    }
    return {stoll(s1), stoll(s2)};
}

int main() {
    vector<ll> availableIngredient;
    vector<pair<ll, ll>> ingredientRange;

    ifstream file("data.txt");
    string line;

    while (getline(file, line)) {
        if (line.find('-') != string::npos) {
            pair<ll, ll> p = parseLine(line);
            ingredientRange.push_back(p);
        }
        else if (!line.empty()) {
            availableIngredient.push_back(stoll(line));
        }
    }
    file.close();

    Solution sol(availableIngredient, ingredientRange);
    ll result = sol.solveP1();
    print(result);

    ll result2 = sol.solveP2();
    print(result2);
    return 0;
}