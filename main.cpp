#include <vector>

int singleNumber(std::vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num; // XOR operation cancels out duplicates
    }
    return result;
}
