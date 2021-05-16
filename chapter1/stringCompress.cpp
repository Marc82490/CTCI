#include <iostream>
#include <vector>
#include <string>

// using namespace std;

std::string compress(std::string s) {
    std::string compStr;
    char currChar{s[0]};
    int count{};

    for (int x{}; x < s.size(); x++)
    {
        if (s[x] == currChar) {
            count++;
        }
        else {
            compStr = compStr + currChar + std::to_string(count);
            currChar = s[x];
            count = 1;
        }
    }

    compStr = compStr + currChar + std::to_string(count);

    return compStr;
}

int main() {
    std::string str;
    std::cin >> str;
    std::string compStr = compress(str);
    std::string outStr = (compStr.size() < str.size()) ? compStr : str;
    std::cout << outStr;
}