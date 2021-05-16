#include <iostream>
#include <vector>
#include <string>

using namespace std;

string compress(string s) {
    string compStr;
    char currChar{s[0]};
    int count{};

    for (int x{}; x < s.size(); x++)
    {
        if (s[x] == currChar) {
            count++;
        }
        else {
            compStr = compStr + currChar + to_string(count);
            currChar = s[x];
            count = 1;
        }
    }

    compStr = compStr + currChar + to_string(count);

    return compStr;
}

int main() {
    string str;
    cin >> str;
    string compStr = compress(str);
    string outStr = (compStr.size() < str.size()) ? compStr : str;
    cout << outStr;
}