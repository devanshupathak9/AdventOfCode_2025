#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
void print(T val) { cout << val; }

template <typename T>
void println(T val) { cout << val << "\n"; }

int countZero(int currPos, vector<string> actions) {
    int counter = 0, rem, quotient;
    for (auto it : actions)
    {
        char ch = it[0];
        int num = stoi(it.substr(1));
        rem = num % 100;
        if (ch == 'L') {
            if (currPos - rem > 0) currPos = currPos - rem;
            else currPos = 100 + (currPos - rem);
        }
        else if (ch == 'R')
        {
            if (currPos + rem < 100) currPos = currPos + rem;
            else currPos = currPos + rem - 100;
        }
        if (currPos == 0 || currPos == 100)
            counter += 1;
    }
    return counter;
}

int main()
{
    int initialPos = 50;
    vector<string> actions;
    ifstream file("data.txt");
    string line;
    while (getline(file, line))
    {
        actions.push_back(line);
    }
    file.close();
    // vector<string> actions = {"L68", "L30", "R48", "L5", "R60", "L55", "L1", "L99", "R14", "L82"};
    int zeros = countZero(initialPos, actions);
    println("Answer:");
    println(zeros);
}