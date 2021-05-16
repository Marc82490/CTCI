#include <iostream>
#include <string>
#include <map>

// using namespace std;

int checkPerms(std::string str1, std::string str2) {
    std::map<char, int> dict1;
    std::map<char, int> dict2;

    for (char ch : str1) {
        // dict1.try_emplace(ch, 1);
        dict1[ch] += 1;
    }

    for (char ch : str2) {
        // dict2.try_emplace(ch, 1);
        // dict2.insert(dict2.find(ch) + 1);
        dict2[ch] += 1;
    }
    
    return dict1 == dict2;
}

int main() {
    std::string str1;
    std::string str2;
    std::cin >> str1 >> str2;
    std::cout << checkPerms(str1, str2);
}