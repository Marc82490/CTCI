#include <iostream>
#include <vector>

// using namespace std;

std::vector<int> buildVector(const std::vector<int>& arr) {
    std::vector<int> tally(arr.size());

    for (int x : arr) {
        tally[(x-1)] += 1;
    }

    return tally;
}

bool checkConsecutive(const std::vector<int>& arr) {
    std::vector<int> tally = buildVector(arr);

    for (int ele : tally) {
        if (ele == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<int> arr{1,3,2,4};
    std::cout << checkConsecutive(arr);
}