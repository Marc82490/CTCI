#include <iostream>
#include <string>
#include <map>

using namespace std;

int checkPerms(string str1, string str2) {
    map<char, int> dict1;
    map<char, int> dict2;

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
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << checkPerms(str1, str2);
}