#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            // Found a duplicate
            return true;
        }

        // Add the element to the set
        seen.insert(num);
    }

    // No duplicates found
    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 2, 3, 4, 5, 6, 7};

    if (containsDuplicate(nums)) {
        std::cout << "The array contains duplicates. True" << std::endl;
    } else {
        std::cout << "The array does not contain duplicates. False" << std::endl;
    }

    return 0;
}
