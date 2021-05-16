#include <iostream>
#include <string>
#include <map>

using namespace std;

int palindromePerm(string str) {
    map<char, int> dict;
    for (char ch : str) {
        if (isalpha(ch)) {
            dict[tolower(ch)] += 1;
        }
    }

    bool flag = false;
    for (pair<char, int> ele : dict) {
        if (ele.second % 2 == 1) {
            if (flag == false) {
                flag = true;
            }
            else if (flag == true) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    cout << palindromePerm(str);
}