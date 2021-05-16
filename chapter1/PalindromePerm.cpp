#include <iostream>
#include <string>
#include <map>

// using namespace std;

int palindromePerm(std::string str) {
    std::map<char, int> dict;
    for (char ch : str) {
        if (isalpha(ch)) {
            dict[tolower(ch)] += 1;
        }
    }

    bool flag = false;
    for (std::pair<char, int> ele : dict) {
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
    std::string str;
    std::getline(std::cin, str);
    std::cout << palindromePerm(str);
}