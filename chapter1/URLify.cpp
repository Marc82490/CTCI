#include <iostream>
#include <string>

// using namespace std;

std::string URL(std::string str1) {
    std::string str2;
    bool flag = false;

    int x = str1.length() - 1;

    for (x; x >= 0; x--) {
        if (flag == false && str1[x] == ' ') {
            continue;
        }
        else if (isalpha(str1[x])) {
            flag = true;
            str2.push_back(str1[x]);
        }
        else if (str1[x] == ' ') {
            str2.append("02%");
        }
    }
    std::string str3(str2.rbegin(), str2.rend());
    return str3;
}

int main() {
    std::string str1 = "a b";
    // cin >> str1;
    std::cout << URL(str1);
}