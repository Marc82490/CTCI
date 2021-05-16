#include <iostream>
#include <vector>

using namespace std;

vector<int> buildVector(const vector<int>& arr) {
    vector<int> tally(arr.size());

    for (int x : arr) {
        tally[(x-1)] += 1;
    }

    return tally;
}

bool checkConsecutive(const vector<int>& arr) {
    vector<int> tally = buildVector(arr);

    for (int ele : tally) {
        if (ele == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> arr{1,3,2,4};
    cout << checkConsecutive(arr);
}