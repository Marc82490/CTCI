#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

// using namespace std;

int strChecker() {
    std::string str = "abca";

    std::vector<int> alpha(26);

    for (auto ch : str) {
        int a{};
        a = ch - 'a';
        if (alpha[a] > 0) {
                return false;
            }
        else {
            alpha[a] += 1;
        }
    }
    return true;
}

int main () {
    std::cout << strChecker();
}